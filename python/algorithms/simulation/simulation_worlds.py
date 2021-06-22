#!/usr/bin/python3
"""defines different 3D world models for simulation and testing algorithms"""

import numpy as np
from enum import Enum
class SceneType(Enum):
    scene_cube = 0
    scene_Hut = 1
    scene_planarWall = 2
    scene_3DVolume = 3
    scene_3DVolume_loop = 4
    scene_custom = 5

class Simulation:
    def __init__(self):
        self.sparsePoints3D = None

    def model_scene(self,scene_attributes):
        """
        :argument scene_attributes: dictionary of scene attributes
        :return: return 3D points on a plane at depth
        """
        self.sparsePoints3D = np.zeros([10, 3])
        scene_type = scene_attributes
        if scene_type == SceneType.scene_planarWall:
            print("create a 2d scene")
        elif scene_type == SceneType.scene_3DVolume:
            print("Create a 3d scene")
        elif scene_type == SceneType.scene_cube:
            print("create a cube")

    def dummy(self,arg1):
        '''

        :param arg1:
        :return:
        '''