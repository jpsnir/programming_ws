import numpy as np
from matplotlib import pyplot as plt
from numpy.testing import assert_allclose
from matplotlib import patches
from mpl_toolkits.mplot3d import Axes3D

# get any random matrix
x_c, y_c, z_c = 0, 0, 0
N = 10
dim = 3
A = np.random.randn(dim, dim)

# this matrix is always positive definite and symmetric
AtA = A.transpose() @ A

u, s, v = np.linalg.svd(A)
cov = AtA
U, S, V = np.linalg.svd(cov)

assert S.shape == (dim,), f"Shape of S is {S.shape}"
assert_allclose(s**2, S)

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
fig = plt.figure()
ax = fig.add_subplot(projection="3d")
ax.plot_wireframe(x, y, z)
plt.show()

# rotate the covariance ellipse:
data = np.kron(U[:, 0:1], x) + np.kron(U[:, 1:2], y) + np.kron(U[:, 2:3], z)
print(f'rotation matrix = {U}')
print(data.shape)
n = data.shape[1]
x, y, z = data[0:n, :], data[n : 2 * n, :], data[2 * n :, :]
fig2 = plt.figure()
ax = fig2.add_subplot(projection="3d")
print(f"shape of x = {x.shape}, y = {y.shape}, z = {z.shape}")
ax.plot_wireframe(x, y, z)
plt.show()
