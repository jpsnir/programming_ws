import cv2 as cv
from enum import Enum


class ReconstructionType(Enum):
    projective = 0
    affine = 1
    metric = 2


class MultiViewGeometry:
    def __init__(self, multi_view_points_2d):
        if len(multi_view_points_2d) > 0:
            self.multi_view_points_2d = multi_view_points_2d
        else:
            self.multi_view_points_2d = {}
        print("init function")

    def reconstruct(self, reconstruction_attributes, *args):
        """
        :argument view_points_2d: dictionary of view - corresponding 2d points list. can store n views and n
        corresponding list of points
        :argument reconstruction_attributes: dictionary that saves attributes required for reconstruction.
        :returns reconstructed_points: list of points in space which are triangulated from two views.
        """
        type = reconstruction_attributes["reconstruction_type"]

        print("")

    def affine_reconstruction(self):
        """
            performs an affine reconstruction of the 2D points of the scene.
            Here parallel lines remain parallel
        """

    def projective_reconstruction(self):
        """
            performs a reconstruction up to projective ambiguity of the 2D points of the scene.
            Straight lines remain straight lines, but parallel lines are not preserved to be parallel.
        """

    def metric_reconstruction(self):
        """
            performs a reconstruction up to scale ambiguity of matched 2D points of the scene
            Orthogonal lines remain orthogonal, parallel lines remain parallel.
        """
