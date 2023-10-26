#include <gtsam/base/Vector.h>
#include <gtsam/geometry/Cal3_S2.h>
#include <gtsam/geometry/Rot3.h>
#include <iostream>

#include <cmath>
#include <gtsam/geometry/Point2.h>
#include <gtsam/geometry/Point3.h>
#include <gtsam/geometry/Pose2.h>
#include <gtsam/inference/ISAM.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/linear/NoiseModel.h>
#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/slam/PriorFactor.h>
#include <gtsam/slam/ProjectionFactor.h>
#include <vector>

#define R 1.0 // m
template <typename T> void print_vector(std::vector<T> &v) {
  for (auto elem : v) {
    std::cout << elem << std::endl;
  }
}

void print_string(std::string s) {
  std::cout << "---------------------\n" << s << "\n";
}
int main() {
  std::cout << " GTSAM camera reconsctruction from simulated points"
            << std::endl;

  // Data setup
  // camera poses
  int N = 10;
  std::vector<gtsam::Pose3> cam_poses;

  // 2d poses around a circle
  // camera moves in xy plane.
  for (int i = 0; i < N; i++) {
    double yaw = 2 * M_PI * i / N;
    double pitch = 0.0;
    double roll = 0.0;
    double x = R * cos(yaw);
    double y = R * sin(yaw);
    double z = 0.0;
    gtsam::Rot3 rotation = gtsam::Rot3::RzRyRx(yaw, pitch, roll);
    gtsam::Point3 p(x, y, z);

    cam_poses.push_back(gtsam::Pose3(rotation, p));
  }

  print_string("camera poses");
  print_vector<gtsam::Pose3>(cam_poses);

  // 3d landmarks in yz plane.
  // this is the structure which we will estimate.
  std::vector<double> y_coordinates{-R / 4, 0, R / 4};
  std::vector<double> z_coordinates{-R / 4, 0, R / 4};

  std::vector<gtsam::Point3> landmarks;
  print_string("y coordinates");
  print_vector<double>(y_coordinates);
  print_string("y coordinates");
  print_vector<double>(z_coordinates);
  for (auto y : y_coordinates) {
    for (auto z : z_coordinates) {
      landmarks.push_back(gtsam::Point3(0, y, z));
    }
  }
  print_string("3D landmarks");
  print_vector<gtsam::Point3>(landmarks);

  gtsam::NonlinearFactorGraph graph;
  auto sigma_theta_rad = gtsam::Vector1::Constant(0.1);
  auto sigma_translation_meter = gtsam::Vector2::Constant(0.3);
  auto cam_pose_sigma =
      (gtsam::Vector(6) << sigma_theta_rad, sigma_translation_meter).finished();
  auto poseNoise = gtsam::noiseModel::Diagonal::Sigmas(cam_pose_sigma);
  graph.addPrior(gtsam::Symbol('l', 0), cam_poses[0], poseNoise);

  // add all other measurements
  gtsam::Cal3_S2::shared_ptr K(new gtsam::Cal3_S2(50.0, 50.0, 0.0, 50.0, 50.0));
  auto measurementNoise = gtsam::noiseModel::Isotropic::Sigma(2, 1);
  for (int i = 0; i < cam_poses.size(); i++) {
    gtsam::PinholeCamera<gtsam::Cal3_S2> camera(cam_poses[i], *K);
    for (int j = 0; j < landmarks.size(); j++) {
      gtsam::Point2 projected_pt = camera.project(landmarks[j]);
      graph.emplace_shared<gtsam::GenericProjectionFactor<
          gtsam::Pose3, gtsam::Point3, gtsam::Cal3_S2>>(
          projected_pt, measurementNoise, gtsam::Symbol('x', i),
          gtsam::Symbol('l', j), K);
    }
  }

  auto landmarkNoise = gtsam::noiseModel::Isotropic::Sigma(3, 0.1);
  graph.addPrior(gtsam::Symbol('l',0), landmarks[0]);
  graph.print("Factor graph:\n");

}
