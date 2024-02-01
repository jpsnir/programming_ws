import numpy as np
from matplotlib import pyplot as plt
from numpy.testing import assert_allclose
from matplotlib import patches
from mpl_toolkits.mplot3d import Axes3D
import gtsam


def plot_covariance(cov: np.ndarray):
    U, S, V = np.linalg.svd(cov)

    assert S.shape == (dim,), f"Shape of S is {S.shape}"
    # assert_allclose(s**2, S)

    print(f"Covariance matrix = {AtA}")
    origin = np.array([x_c, y_c, z_c])
    confidence = 1.96  # 95% confidence
    # get the standard deviation along principal directions
    if dim == 6:
        r1, r2, r3 = confidence * np.sqrt(S[3:6])
    else:
        r1, r2, r3 = confidence * np.sqrt(S)

    # make ellipsoid
    # to include the last value add 1.
    th = np.linspace(0, 2 * np.pi, N + 1)
    phi = np.linspace(-np.pi / 2, np.pi / 2, N + 1)

    # for each element of th we will rotate around an ellipse.
    # coordinates obey ellipsoid equation:
    # x^2/r1^2 + y^2/r2^2 + z^2/r3^2 = 1
    x = r1 * np.outer(np.cos(th), np.cos(phi)).T
    y = r2 * np.outer(np.sin(th), np.cos(phi)).T
    z = r3 * np.outer(np.ones_like(th), np.sin(phi)).T

    print(f"shape of x = {x.shape}, y = {y.shape}, z = {z.shape}")
    # fig = plt.figure()
    # ax = fig.add_subplot(projection="3d")
    # ax.plot_wireframe(x, y, z)
    # plt.show()

    # rotate the covariance ellipse:
    data = np.kron(U[:, 0:1], x) + np.kron(U[:, 1:2], y) + np.kron(U[:, 2:3], z)
    print(f"rotation matrix = {U}")
    print(data.shape)
    n = data.shape[1]
    x, y, z = data[0:n, :], data[n : 2 * n, :], data[2 * n :, :]
    fig2 = plt.figure()
    ax = fig2.add_subplot(projection="3d")
    print(f"shape of x = {x.shape}, y = {y.shape}, z = {z.shape}")
    ax.plot_wireframe(x, y, z)


def set_axes_equal(ax):
    """
    Make axes of 3D plot have equal scale so that spheres appear as spheres,
    cubes as cubes, etc.

    Input
      ax: a matplotlib axis, e.g., as output from plt.gca().
    """

    x_limits = ax.get_xlim3d()
    y_limits = ax.get_ylim3d()
    z_limits = ax.get_zlim3d()

    x_range = abs(x_limits[1] - x_limits[0])
    x_middle = np.mean(x_limits)
    y_range = abs(y_limits[1] - y_limits[0])
    y_middle = np.mean(y_limits)
    z_range = abs(z_limits[1] - z_limits[0])
    z_middle = np.mean(z_limits)

    # The plot bounding box is a sphere in the sense of the infinity
    # norm, hence I call half the max range the plot radius.
    plot_radius = 0.5 * max([x_range, y_range, z_range])

    ax.set_xlim3d([x_middle - plot_radius, x_middle + plot_radius])
    ax.set_ylim3d([y_middle - plot_radius, y_middle + plot_radius])
    ax.set_zlim3d([z_middle - plot_radius, z_middle + plot_radius])


def plot_pose_covariance(pose: gtsam.Pose3, cov: np.ndarray, axis_length: float = 0.1):
    w_R_p = pose.rotation().matrix()
    origin = pose.translation()
    fig = plt.figure()
    ax = fig.add_subplot(projection="3d")
    # unit vector along x axis is w_R_p[:, 0]
    x_axis = origin + w_R_p[:, 0] * axis_length
    line = np.append(origin[np.newaxis], x_axis[np.newaxis], axis=0)
    xaxis = w_R_p[:, 0].ravel() * axis_length  # flattening just in case
    yaxis = w_R_p[:, 1].ravel() * axis_length
    zaxis = w_R_p[:, 2].ravel() * axis_length
    y_axis = origin + w_R_p[:, 1] * axis_length
    line = np.append(origin[np.newaxis], y_axis[np.newaxis], axis=0)
    ax.plot(line[:, 0], line[:, 1], line[:, 2], "g-")

    z_axis = origin + w_R_p[:, 2] * axis_length
    line = np.append(origin[np.newaxis], z_axis[np.newaxis], axis=0)
    ax.plot(line[:, 0], line[:, 1], line[:, 2], "b-")
    print(f"dot product = {xaxis} {yaxis} - {xaxis.dot(yaxis)}")

    ax.plot(line[:, 0], line[:, 1], line[:, 2])
    ax.quiver(
        origin[0],
        origin[1],
        origin[2],
        xaxis[0],
        xaxis[1],
        xaxis[2],
        color="r",
    )
    ax.quiver(
        origin[0],
        origin[1],
        origin[2],
        yaxis[0],
        yaxis[1],
        yaxis[2],
        color="g",
    )
    ax.quiver(
        origin[0],
        origin[1],
        origin[2],
        zaxis[0],
        zaxis[1],
        zaxis[2],
        color="b",
    )

    P_position = cov[3:6, 3:6]
    plot_covariance(P_position)
    # using the definition of covariance Cov(x) = E((x-x_mean)(x-x_mean)^T)
    # Cov(x_w) = E(R(x-x_mean)(x-x_mean)^T R^T)
    # Cov(x_w) = R cov(x_p) R^T
    gP = w_R_p @ P_position @ w_R_p.T
    plot_covariance(P_position)
    # perpective difference can show that it does not match.
    set_axes_equal(ax)
    plt.show()


# usage of quiver function
def plot_arrow():
    fig = plt.figure()
    ax = fig.add_subplot(projection="3d")
    # x, y and z coordinates have to be specified to determine the start of
    # arrow locations.
    # U,V , W are directions of the arrows. each element in u , v and w
    # gives us a direction vector. In this example it is pointing in the direction of
    # x axis.
    ax.quiver([1, 1.2, 1.4], [0, 0, 0], [0, 0, 0], 0.1, 0, 0, linewidth=2)
    plt.show()


# get any random matrix
x_c, y_c, z_c = 0, 0, 0
N = 10
dim = 3
A = np.random.randn(dim, dim)

# this matrix is always positive definite and symmetric
AtA = A.transpose() @ A

u, s, v = np.linalg.svd(A)
cov = AtA
plot_covariance(cov)
plt.show()
theta = np.pi / 3
R = np.array(
    [[np.cos(theta), -np.sin(theta), 0], [np.sin(theta), np.cos(theta), 0], [0, 0, 1]]
)
rot = gtsam.Rot3(R=R)
pose = gtsam.Pose3(r=rot, t=np.array([0, 0, 0]))
A = np.random.randn(6, 6)
AtA = A.T @ A
cov = AtA
plot_pose_covariance(pose, cov)
