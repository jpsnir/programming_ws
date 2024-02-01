import argparse
import math

import matplotlib.pyplot as plt
import numpy as np
from gtsam.symbol_shorthand import B, V, X
from gtsam.utils.plot import plot_pose3
from mpl_toolkits.mplot3d import Axes3D
from gtsam.examples.PreintegrationExample import POSES_FIG, PreintegrationExample

# from gtsam.examples.ImuFactorExample import ImuFactorExample as ImuFactorExampleOrig
import gtsam
import signal
import sys

BIAS_KEY = B(0)
GRAVITY = 9.81

np.set_printoptions(precision=3, suppress=True)

def signal_handler(sig, frame):
    print("exiting")
    sys.exit(0)

def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser("Imu Factor")
    parser.add_argument(
        "--twist_scenario",
        default="sick_twist",
        choices=["zero_twist", "forward_twist", "loop_twist", "sick_twist"],
    )
    parser.add_argument(
        "--time", "-T", default=12, type=int, help="Total navigation time in seconds"
    )
    parser.add_argument("--compute_covariances", default=False, action="store_true")
    parser.add_argument("--verbose", default=False, action="store_true")
    args = parser.parse_args()
    return args


class ImuFactorExample(PreintegrationExample):
    def __init__(self, twist_scenario: str = "sick_twist"):
        self.velocity = np.array([2, 0, 0])
        self.priorNoise = gtsam.noiseModel.Isotropic.Sigma(6, 0.1)
        self.velNoise = gtsam.noiseModel.Isotropic.Sigma(3, 0.1)

        twist_scenarios = dict(
            zero_twist=(np.zeros(3), np.zeros(3)),
            forward_twist=(np.zeros(3), self.velocity),
            loop_twist=(np.array([0, np.radians(30), 0]), self.velocity),
            sick_twist=(np.array([np.radians(30), -np.radians(30), 0]), self.velocity),
        )

        accBias = np.array([-0.3, 0.1, 0.2])
        gyroBias = np.array([0.1, 0.3, -0.1])
        bias = gtsam.imuBias.ConstantBias(accBias, gyroBias)
        params = gtsam.PreintegrationParams.MakeSharedU(GRAVITY)

        gyro_sigma = 1e-3
        accel_sigma = 1e-3
        I_3x3 = np.eye(3)
        params.setGyroscopeCovariance(gyro_sigma**2 * I_3x3)
        params.setAccelerometerCovariance(accel_sigma**2 * I_3x3)
        params.setIntegrationCovariance(1e-7**2 * I_3x3)
        dt = 1e-2
        super(ImuFactorExample, self).__init__(
            twist_scenarios[twist_scenario], bias, params, dt
        )

    def addPrior(self, i: int, graph: gtsam.NonlinearFactorGraph):
        state = self.scenario.navState(i)
        graph.push_back(gtsam.PriorFactorPose3(X(i), state.pose(), self.priorNoise))
        graph.push_back(gtsam.PriorFactorVector(V(i), state.velocity(), self.velNoise))

    def optimize(self, graph: gtsam.NonlinearFactorGraph, initial: gtsam.Values):
        params = gtsam.LevenbergMarquardtParams()
        params.setVerbosityLM("SUMMARY")
        optimizer = gtsam.LevenbergMarquardtOptimizer(graph, initial, params)
        result = optimizer.optimize()
        return result

    def plot(
        self,
        values: gtsam.Values,
        title: str = "Estimated Trajectory",
        fignum: int = POSES_FIG + 1,
        show: bool = False,
    ):
        i = 0
        while values.exists(X(i)):
            pose_i = values.atPose3(X(i))
            plot_pose3(fignum, pose_i, 1)
            i += 1

        plt.title(title)
        gtsam.utils.plot.set_axes_equal(fignum)
        print("Bias Values", values.atConstantBias(BIAS_KEY))
        plt.ioff()

        if show:
            plt.show()

    def run(self, T: int = 12, compute_covariances: bool = False, verbose: bool = True):
        graph = gtsam.NonlinearFactorGraph()
        pim = gtsam.PreintegratedImuMeasurements(self.params, self.actualBias)
        num_poses = T
        initial = gtsam.Values()
        initial.insert(BIAS_KEY, self.actualBias)
        i = 0
        initial_state_i = self.scenario.navState(0)
        initial.insert(X(i), initial_state_i.pose())
        initial.insert(V(i), initial_state_i.velocity())

        self.addPrior(0, graph)
        #print(list(enumerate(np.arange(0, T, 1e-2))))
        for k, t in enumerate(np.arange(0, T, 1e-2)):
            measuredOmega = self.runner.measuredAngularVelocity(t)
            measuredAcc = self.runner.measuredSpecificForce(t)
            pim.integrateMeasurement(measuredAcc, measuredOmega, self.dt)
            if k % 10 == 0:
                self.plotImu(t, measuredOmega, measuredAcc)
                plt.pause(0.1)

            if (k + 1) % int(1 / self.dt) == 0:
                self.plotGroundTruthPose(t, scale=1)
                plt.title("ground truth trajecotry")
                #print(f"inserting factor {i}")
                factor = gtsam.ImuFactor(X(i), V(i), X(i + 1), V(i + 1), BIAS_KEY, pim)
                graph.push_back(factor)
                print("factor pushed")
                if verbose:
                    print(factor)
                    print(
                        f"Predicted state at {t + self.dt} : \n {pim.predict(initial_state_i, self.actualBias)}"
                    )
                pim.resetIntegration()

                rotationNoise = gtsam.Rot3.Expmap(np.random.randn(3) * 0.1)
                translationNoise = gtsam.Point3(np.random.randn(3) * 1)
                poseNoise = gtsam.Pose3(rotationNoise, translationNoise)

                actual_state_i = self.scenario.navState(t + self.dt)
                print(f"Actual state at {t + self.dt}  \n {actual_state_i}")
                initial_state_i = actual_state_i

                noisy_state_i = gtsam.NavState(
                    actual_state_i.pose().compose(poseNoise),
                    actual_state_i.velocity() + np.random.randn(3) * 0.1,
                )
                initial.insert(X(i + 1), noisy_state_i.pose())
                initial.insert(V(i + 1), noisy_state_i.velocity())
                i += 1

        print(t)
        print(f"optmizing here")
        self.addPrior(num_poses - 1, graph)
        initial.print("Initial values:")
        result = self.optimize(graph, initial)
        result.print("Optmized values")
        print("-----------")
        print(graph.error(initial))
        print(graph.error(result))
        print("------------------")

        if compute_covariances:
            marginals = gtsam.marginalCovariances(BIAS_KEY)
            print("Covariance on bias:\n", marginals.marginalCovariance(BIAS_KEY))
            for i in range(num_poses):
                print(
                    f"Covariance on pose {i} : \n {marginals.marginalCovariance(X(i))}"
                )
                print(
                    "Covariance on vel {}:\n{}\n".format(
                        i, marginals.marginalCovariance(V(i))
                    )
                )
        self.plot(result, show=True)


if __name__ == "__main__":
    args = parse_args()
    signal.signal(signal.SIGINT, signal_handler)
    ImuFactorExample(args.twist_scenario).run(
        args.time, args.compute_covariances, args.verbose
    )
