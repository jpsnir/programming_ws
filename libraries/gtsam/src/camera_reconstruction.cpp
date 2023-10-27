#include <iostream>
#include <cstdio>
#include <SFMdata.h>
#include <cmath>
#include <gtsam/base/Matrix.h>
#include <gtsam/base/Vector.h>
#include <gtsam/geometry/Cal3_S2.h>
#include <gtsam/geometry/Point2.h>
#include <gtsam/geometry/Point3.h>
#include <gtsam/geometry/Pose2.h>
#include <gtsam/geometry/Rot3.h>
#include <gtsam/inference/ISAM.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/linear/NoiseModel.h>
#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>
#include <gtsam/slam/PriorFactor.h>
#include <gtsam/slam/ProjectionFactor.h>
#include <vector>
#define R 30.0f  // m
#define FX 60.0f // pixels
#define FY 60.0f // pixels
#define CX 50.0f // pixels
#define CY 50.0f // pixels
template <typename T> void print_vector(std::vector<T> &v) {
  for (int i = 0; i < v.size(); i++) {
    std::cout << "item = " << i << std::endl;
    std::cout << v[i] << std::endl;
    std::cout << "-------------------------------" << std::endl;
  }
}

void print_string(std::string s) {
  std::cout << "---------------------\n" << s << "\n";
}

void create_camera_poses(std::vector<gtsam::Pose3> &cam_poses) {
  // world - x - forward, y - right, z - down
  // camera - z-forward, x - right, y - down
  // 2d poses around a circle
  // camera moves in xy plane.
  int N = 12;
  for (int i = 0; i < N; i++) {
    double theta = 2 * M_PI * i / N;
    std::cout << "theta = " << theta * 180 / M_PI << ",";
    double yaw = -M_PI / 2 - theta;
    double pitch = 0.0;
    double roll = 0.0;
    double x = R * cos(theta);
    double y = R * sin(theta);
    double z = 0.0;
    gtsam::Rot3 world_R_body = gtsam::Rot3::Yaw(yaw);
    gtsam::Matrix3 mat;
    mat << 0, 0, 1, 1, 0, 0, 0, 1, 0;
    gtsam::Rot3 body_R_cam = gtsam::Rot3(mat);
    gtsam::Point3 p(x, y, z);
    cam_poses.push_back(gtsam::Pose3(world_R_body * body_R_cam, p));
  }
}

void create_landmarks_on_xz_plane(std::vector<gtsam::Point3> &landmarks) {
  // 3d landmarks in xz plane.
  // this is the structure which we will estimate.
  std::vector<double> x_coordinates{-R / 3, 0, R / 3};
  std::vector<double> z_coordinates{-R / 3, 0, R / 3};

  for (auto x : x_coordinates) {
    for (auto z : z_coordinates) {
      landmarks.push_back(gtsam::Point3(x, 10, z));
    }
  }
}

gtsam::Vector3 project_points(const gtsam::Point3 &lm_w,
                              const gtsam::Pose3 &cam_pose,
                              const gtsam::Cal3_S2::shared_ptr &K) {
  gtsam::Vector4 lm_w_;
  lm_w_ << lm_w, 1;
  std::cout << "landmark in world frame" << std::endl;
  std::cout << lm_w_ << std::endl;
  std::cout << " c_T_w (inverse of cam pose) \n " << cam_pose.inverse()
            << std::endl;
  gtsam::Vector4 pt = cam_pose.matrix().inverse() * lm_w_;
  printf("landmark in camera frame");
  std::cout << pt << std::endl;
  gtsam::Vector3 pt_ =
      gtsam::Vector3(pt[0] / pt[3], pt[1] / pt[3], pt[2] / pt[3]);
  gtsam::Vector3 prj_pt;
  prj_pt << K->matrix() * pt_;
  std::cout << prj_pt / prj_pt[2] << std::endl;
  return prj_pt;
}

int main() {
  std::cout << " GTSAM camera reconsctruction from simulated points"
            << std::endl;

  // Data setup
  // camera poses
  std::vector<gtsam::Pose3> cam_poses;
  std::vector<gtsam::Point3> landmarks;
  create_camera_poses(cam_poses);
  create_landmarks_on_xz_plane(landmarks);
  print_string("camera poses on xy plane");
  print_vector<gtsam::Pose3>(cam_poses);
  print_string("3D landmarks on xz plane");
  print_vector<gtsam::Point3>(landmarks);

  // From sfm example datao
  // cube points and circular motion.
  std::vector<gtsam::Pose3> sfm_example_poses = createPoses();
  std::vector<gtsam::Point3> sfm_example_points = createPoints();

  gtsam::NonlinearFactorGraph graph;
  print_string("Noise definitions");
  auto sigma_theta_rad = gtsam::Vector3::Constant(0.1);
  auto sigma_translation_meter = gtsam::Vector3::Constant(0.3);
  auto cam_pose_sigma =
      (gtsam::Vector(6) << sigma_theta_rad, sigma_translation_meter).finished();
  auto poseNoise = gtsam::noiseModel::Diagonal::Sigmas(cam_pose_sigma);
  graph.addPrior(gtsam::Symbol('l', 0), cam_poses[0], poseNoise);

  auto measurementNoise = gtsam::noiseModel::Isotropic::Sigma(2, 1);

  // add all other measurements
  print_string("adding measurements to factor graph");
  gtsam::Cal3_S2::shared_ptr K(new gtsam::Cal3_S2(FX, FY, 0.0, CX, CY));
  print_string("K matrix");
  std::cout << K->matrix() << std::endl;

  gtsam::PinholeCamera<gtsam::Cal3_S2> camera(sfm_example_poses[0], *K);
  gtsam::Pose3 cam_pose = sfm_example_poses[0];
  auto projector_lambda = [&camera, &cam_pose, &K](std::vector<gtsam::Point3> &landmarks) {
    for (int pt_ctr = 0; pt_ctr < landmarks.size(); pt_ctr++) {
      gtsam::Point2 projected_pt = camera.project(landmarks[pt_ctr]);
      print_string("projected points");
      std::cout << projected_pt << std::endl;
      project_points(landmarks[pt_ctr], cam_pose, K);
    }
  };
  print_string("Cube points projection");
  projector_lambda(sfm_example_points);
  print_string("XZ plane points projection");
  projector_lambda(landmarks);



  for (int i = 0; i < sfm_example_poses.size(); i++) {
    gtsam::PinholeCamera<gtsam::Cal3_S2> camera(sfm_example_poses[i], *K);
    for (int j = 0; j < landmarks.size(); j++) {
      gtsam::Point2 projected_pt = camera.project(sfm_example_points[j]);
      graph.emplace_shared<gtsam::GenericProjectionFactor<
          gtsam::Pose3, gtsam::Point3, gtsam::Cal3_S2>>(
          projected_pt, measurementNoise, gtsam::Symbol('x', i),
          gtsam::Symbol('l', j), K);
    }
  }

   auto landmarkNoise = gtsam::noiseModel::Isotropic::Sigma(3, 0.1);
   graph.addPrior(gtsam::Symbol('l', 0), landmarks[0]);
   graph.print("Factor graph:\n");

   using namespace gtsam;
   gtsam::Values initialEstimate;
   for (int i = 0; i < cam_poses.size(); i++) {
     auto corrupted_pose = cam_poses[i].compose(
         Pose3(Rot3::RzRyRx(-0.1, 0.2, 0.25), Point3(0.05, -0.10, 0.20)));
     initialEstimate.insert(Symbol('x', i), corrupted_pose);
   }
   for (int j = 0; j < landmarks.size(); j++) {
     Point3 corrupted_point = landmarks[j] + Point3(-0.25, 0.20, 0.15);
     initialEstimate.insert<Point3>(Symbol('l', j), corrupted_point);
   }
   initialEstimate.print("Initial Estimates:\n");
}
