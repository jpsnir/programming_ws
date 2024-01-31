import math
import matplotlib.pyplot as plt
import gtsam
from gtsam.symbol_shorthand import B, V, X
from gtsam.utils.plot import plot_pose3
from mpl_toolkits.mplot3d import Axes3D
from typing import Optional, Sequence
import numpy as np
import signal 
import sys

IMU_FIG = 1
POSES_FIG = 2
GRAVITY = 10

def signal_handler(sig, frame):
    print("Pressed Ctrl + c, exiting")
    sys.exit(0)

class PreintegrationExample:
    @staticmethod
    def defaultParams(g: float, kgyro = np.radians(0.5)/60, kacc = 0.1/60, int_sigma = 1e-7):
        params = gtsam.PreintegrationParams.MakeSharedU(g)
        kGyroSigma = 0  # np.radians(0.5) / 60  # white noise
        kAccelSigma = 0  # 0.1 / 60
        integration_sigma = 0  # 1e-7
        # covariance = sigma**2
        params.setAccelerometerCovariance(kGyroSigma**2 * np.identity(3, float))
        params.setAccelerometerCovariance(kGyroSigma**2 * np.identity(3, float))
        params.setIntegrationCovariance(integration_sigma**2 * np.identity(3, float))
        return params

    def __init__(
        self,
        twist: Optional[np.ndarray] = None,
        bias: Optional[gtsam.imuBias.ConstantBias] = None,
        params: Optional[gtsam.PreintegrationParams] = None,
        dt: float = 1e-2,
    ):
        plt.ion()

        if twist is not None:
            (W, V) = twist
        else:
            W = np.array([0, -np.radians(30), 0])
            V = np.array([2, 0, 0])

        self.scenario = gtsam.ConstantTwistScenario(W, V)
        self.dt = dt
        self.maxDim = 5
        self.labels = list("xyz")
        self.colors = list("rgb")
        if params:
            self.params = params
        else:
            self.params = self.defaultParams(g=GRAVITY)

        if bias is not None:
            self.actualBias = bias
        else:
            accBias = np.array([0, 0.1, 0])
            gyroBias = np.array([0, 0, 0])
            self.actualBias = gtsam.imuBias.ConstantBias(accBias, gyroBias)
        print(f'params : { self.params}')
        print(f'biases : {self.actualBias}')
        self.runner = gtsam.ScenarioRunner(
            self.scenario, self.params, self.dt, self.actualBias
        )
        fig, self.axes = plt.subplots(4, 3)
        fig.set_tight_layout(True)

    def plotImu(self, t: float, measuredOmega: Sequence, measuredAcc: Sequence):
        plt.figure(IMU_FIG)
        omega_b = self.scenario.omega_b(t)
        for i, (label, color) in enumerate(zip(self.labels, self.colors)):
            ax = self.axes[0][i]
            ax.scatter(t, omega_b[i], color="k", marker=".")
            ax.scatter(t, measuredOmega[i], color=color, marker=".")
            ax.set_xlabel("angular velocity" + label)

        acceleration_n = self.scenario.acceleration_n(t)
        for i, (label, color) in enumerate(zip(self.labels, self.colors)):
            ax = self.axes[1][i]
            ax.scatter(t, acceleration_n[i], color="k", marker=".")
            ax.scatter(t, acceleration_n[i], color=color, marker=".")
            ax.set_xlabel("acceleration in navigation frame" + label)

        acceleration_b = self.scenario.acceleration_b(t)
        for i, (label, color) in enumerate(zip(self.labels, self.colors)):
            ax = self.axes[2][i]
            ax.scatter(t, acceleration_b[i], color="k", marker=".")
            ax.scatter(t, acceleration_b[i], color=color, marker=".")
            ax.set_xlabel("acceleration in body frame" + label)

        actual = self.runner.actualSpecificForce(t)
        for i, (label, color) in enumerate(zip(self.labels, self.colors)):
            ax = self.axes[3][i]
            ax.scatter(t, actual[i], color="k", marker=".")
            ax.scatter(t, actual[i], color=color, marker=".")
            ax.set_xlabel("Specific force" + label)

    def run(self, T: int = 12):
        """Simulate the loop."""
        for i, t in enumerate(np.arange(0, T, self.dt)):
            measuredOmega = self.runner.measuredAngularVelocity(t)
            measuredAcc = self.runner.measuredSpecificForce(t)
            if i % 10 == 0:
                self.plotImu(t, measuredOmega, measuredAcc)
                self.plotGroundTruthPose(t)
                pim = self.runner.integrate(t, self.actualBias, True)
                predictedNavState = self.runner.predict(pim, self.actualBias)
                plot_pose3(POSES_FIG, predictedNavState.pose(), 0.1)

        plt.ioff()
        plt.show()

    def plotGroundTruthPose(
        self, t: float, scale: float = 0.3, time_interval: float = 0.01
    ):
        """
        Plot ground truth pose, as well as prediction from integrated IMU measurements.
        Args:
            t: Time at which the pose was obtained.
            scale: The scaling factor for the pose axes.
            time_interval: The time to wait before showing the plot.
        """
        actualPose = self.scenario.pose(t)
        plot_pose3(POSES_FIG, actualPose, scale)
        translation = actualPose.translation()
        self.maxDim = max([max(np.abs(translation)), self.maxDim])
        ax = plt.gca()
        ax.set_xlim3d(-self.maxDim, self.maxDim)
        ax.set_ylim3d(-self.maxDim, self.maxDim)
        ax.set_zlim3d(-self.maxDim, self.maxDim)

        plt.pause(time_interval)


if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)
    imu_params = PreintegrationExample.defaultParams(
                g=GRAVITY, kgyro=0, kacc=0,int_sigma=0
            )
    accBias = np.array([0, 0, 0])
    gyroBias = np.array([0, 0, 0])
    const_bias = gtsam.imuBias.ConstantBias(accBias, gyroBias)
    p_int = PreintegrationExample(bias=const_bias,
                                  params=imu_params)
    p_int.run()
