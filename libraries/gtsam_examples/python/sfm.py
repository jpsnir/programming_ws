import gtsam
import matplotlib.pyplot as plt
import numpy as np
from gtsam import symbol_shorthand

L = symbol_shorthand.L
X = symbol_shorthand.X

from gtsam.examples import SFMdata
from gtsam import (
    Cal3_S2,
    DoglegOptimizer,
    GenericProjectionFactorCal3_S2,
    Marginals,
    NonlinearFactorGraph,
    PinholeCameraCal3_S2,
    Point3,
    Pose3,
    PriorFactorPoint3,
    PriorFactorPose3,
    Rot3,
    Values,
)

from gtsam.utils import plot


def main():
    K = gtsam.Cal3_S2(50.0, 50.0, 0.0, 50.0, 50.0)
    measurement_noise = gtsam.noiseModel.Isotropic.Sigma(2, 1.0)  # 1 pixel noise
    # store camera observations
    pts = SFMdata.createPoints()
    poses = SFMdata.createPoses(K)
    graph = NonlinearFactorGraph()

    # pose noise roll, pitch, yaw, x, y, z for that local coordinates axis.
    pose_noise = gtsam.noiseModel.Diagonal.Sigmas(
        np.array([0.3, 0.3, 0.3, 0.1, 0.1, 0.1])
    )
    factor = PriorFactorPose3(X(0), poses[0], pose_noise)
    graph.push_back(factor)

    for i, pose in enumerate(poses):
        camera = PinholeCameraCal3_S2(pose, K)
        for j, point in enumerate(pts):
            measurement = camera.project(point)
            factor = GenericProjectionFactorCal3_S2(
                measurement, measurement_noise, X(i), L(j), K
            )
            graph.push_back(factor)

    # fix scale by adding a prior to the landmark
    point_noise = gtsam.noiseModel.Isotropic.Sigma(3, 0.1)
    factor = PriorFactorPoint3(L(0), pts[0], point_noise)
    graph.push_back(factor)
    graph.print("Factor graph \n")

    initial_estimate = Values()
    for i, pose in enumerate(poses):
        # perturb the actual poses by little bit
        transformed_pose = pose.retract(0.1 * np.random.randn(6, 1))
        initial_estimate.insert(X(i), transformed_pose)

    for j, point in enumerate(pts):
        transformed_point = point + 0.1 * np.random.randn(3)
        initial_estimate.insert(L(j), transformed_point)
    initial_estimate.print("Initial Estimates: \n")

    # configure the solver
    params = gtsam.DoglegParams()
    params.setVerbosity("TERMINATION")
    optimizer = DoglegOptimizer(graph, initial_estimate, params)
    print("Optimization processing:")
    result = optimizer.optimize()
    result.print("Final results:\n")
    print(f"initial error = {graph.error(initial_estimate)}")
    print(f"final error = {graph.error(result)}")

    # marginal
    marginals = Marginals(graph, result)
    plot.plot_3d_points(1, result, marginals=marginals)
    #plot.plot_trajectory(1, result, marginals=marginals, scale=8)
    plot.set_axes_equal(1)
    plt.show()


if __name__ == "__main__":
    main()
