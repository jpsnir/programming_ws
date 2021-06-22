""" Finite camera models definition
    Author: Peter Test
    Date created: 4/20/2013
    Date last modified: 4/25/2013
    Python Version: 3.6
"""
import os
import cv2 as cv
import numpy as np

class Cameras:
    def __init__(self):
        print("init cameras")
        self.w_T_c = np.eye(4) # pose of camera
        self.f = np.array([1,1]) #focal length (fx,fy)
        self.c = np.array([0,0]); # optical center of camera
        self.tangentialDistortion = np.zeros([4,1]) # tangential distortion parameters of camera
        self.radialDistortion = np.zeros([2,1]) # radial distortion parameters of camera
        self.HFOV = np.deg2rad(53) # horizontal field of view
        self.VFOV = np.deg2rad(53) # vertical field of view

    def IntrinsicMatrix(self):
        """
        returns intrinsic camera matrix.
        :return: numpy array 3x3 intrinsic matrix
        :
        """
        self.K = np.array[[self.f[0],0,self.c[0]],\
                          [0,self.f[1],self.c[1]],\
                          [0,0,1]];
        return self.K

    def ProjectionMatrix(self):
        """
        returns projection matrix of camera.
        """
        print("projection matrix")

    def ProjectRay(self,pixelCoordinate):
        """
        returns coefficients of 3D ray projected from camera
        """

    def PointInFieldOfView(self,point3D):
        """
         point3D :argument numpy array, location of 3D point
         :returns true if 3D point is in field of view of camera
        """
