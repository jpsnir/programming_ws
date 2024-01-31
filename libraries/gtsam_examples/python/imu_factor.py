import argparse
import math

import matplotlib.pyplot as plt
import numpy as np
from gtsam.symbol_shorthand import B, V, X
from gtsam.utils.plot import plot_pose3
from mpl_toolkits.mplot3d import Axes3D
from gtsam.examples.PreintegrationExample import POSES_FIG, PreintegrationExample

import gtsam

BIAS_KEY= B(0)
GRAVITY = 9.81

np.set_printoptions(precision=3, suppress=True)

def parse_args() -> argparse.Namespace:
    
    parser = argparse.ArgumentParser("Imu Factor")
    parser.add_argument("--twist_scenario", 
                        default = "sick_twist",
                        choices=["zero_twist", "forward_twist", "loop_twist", "sick_twist"])
    parser.add_argument("--time", "-T",
                        default=12,
                        type=int,
                        help="Total navigation time in seconds")
    parser.add_argument("--compute_covariances",
                        default=False,
                        action='store_true')
    parser.add_argument("--verbose", default=False, action='store_true')
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
            loop_twist = (np.array([0, np.radians(30), self.velocity])),
            sick_twist = (np.array([np.radians(30), -np.radians(30), 0]), self.velocity)
        )

        accBias = np.array([-0.3, 0.1, 0.2])
        gyroBias = np.array([0.1, 0.3, -0.1])

