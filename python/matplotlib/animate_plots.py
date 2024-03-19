import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from typing import Union

def projectile(v0_z: float, t: Union[float, np.ndarray], g:float = -9.81) -> Union[float, np.ndarray]:
    """
    simulate the motion of a projection
    """

    z = 0.5 * g * t**2 + v0_z*t
    return z
    

fig, ax = plt.subplots()
time = np.linspace(0, 3, 40)
v1  = 12
v2 = 5
z1 = projectile(v0_z=v1, t=time)
z2 = projectile(v0_z=v2, t=time)
print(f" height = {z1}")

scat = ax.scatter(time[0], z1[0], c="b", s=5, label=f'v0 = {v1} m/s')
line2 = ax.plot(time[0], z2[0], label=f'v0 = {v2} m/s')[0]
ax.set(xlim=[0, 3], ylim=[-4, 10], xlabel='Time [s]', ylabel='Z [m]')
ax.legend()

def update(frame):
    x = time[:frame]
    y = z1[:frame]
    # for scatter plot we are using its artist
    data = np.stack([x, y]).T
    scat.set_offsets(data)

    # for line plot we are using the line artist
    line2.set_xdata(time[:frame])
    line2.set_ydata(z2[:frame])

    return (scat, line2)

# create animation
ani = animation.FuncAnimation(fig=fig, func=update, frames=40, interval=30)
plt.show()

# animation with artist animation
fig, ax = plt.subplots()

# random data
rng = np.random.default_rng(1968081)
data = np.array([20, 20, 20, 20])
x = np.array([1, 2, 3, 4])
artists = []
colors = ['tab:blue', 'tab:red', 'tab:green', 'tab:purple']
for i in range(20):
    data += rng.integers(low=0, high=10, size=data.shape)
    