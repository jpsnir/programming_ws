#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Geometry/Transform.h>
#include <eigen3/Eigen/src/Geometry/Translation.h>
#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <numbers>
using namespace std;


TEST(test_geometry, rotationTypes){

    // define 2d rotation
    Eigen::Rotation2D<float> rot2(M_PI/4);

    Eigen::Matrix2f mat;
    mat << cos(M_PI/4), -sin(M_PI/4),
           sin(M_PI/4), cos(M_PI/4);
    std::cout << rot2.matrix() << endl;
    std::cout << mat << endl;
    ASSERT_TRUE(mat.isApprox(rot2.matrix()));

    // 3d rotations
    cout << " Angle axis" << endl;
    Eigen::AngleAxis<float> aa(M_PI/4, Eigen::Vector3f(1, 1, 1).normalized());

    std::cout << aa.matrix() << endl;

    Eigen::Quaternion<float> q;
    q = aa;
    cout << " Quaternion = \n" << q.matrix() << endl;
    cout << " Quaternion = \n" << q.x() << "," << q.y() << "," << q.z() << "," << q.w() << endl;

    // Scaling

    Eigen::Scaling(0.1, 0.2);

    // Matrices are interchangeable
    Eigen::Rotation2D<float> rot(M_PI/2);
    mat = rot;
    mat = rot2;

    aa = q;

    Eigen::Affine3f m;
    m = aa;
}

TEST(test_geometry, transformationTypes){
    Eigen::Vector2f p1, p2;
    p1 << 1, 0;
    p2 << 0, 1;
    Eigen::Vector2f v1(1, 1);

    Eigen::Rotation2D<float> rot(M_PI/2);
    cout << " Rotation of 2D points" << endl;
    cout << p1.transpose() << " rotated to " << (rot*p1).transpose() << endl;
    cout << p2.transpose() << " rotated to " << (rot*p2).transpose() << endl;

    cout << " Vector rotation " << endl;
    cout << v1.transpose() << " rotated to : " << rot * v1 << endl;
}
TEST(test_distortion, lineDistortion){

    Eigen::Matrix<float, 100, 2> pts;
    Eigen::VectorXf x = Eigen::VectorXf::LinSpaced(100, 10, 90);
    Eigen::VectorXf y = 10*Eigen::VectorXf::Ones(100);
    pts << x, y;
    //cout << pts << endl;
    Eigen::Vector2f k, t;
    k << -0.28340811, 0.07395907;
    t << 0.00019359, 1.76187114e-05;
}

TEST(test_geometry, transformation_ND){
    Eigen::Transform<double, 3, Eigen::Isometry> t1;
    Eigen::Isometry3d t2;
    Eigen::AngleAxis<double> aa(M_PI/4, Eigen::Vector3d::Zero());
    cout << " Angle axis representation :\n " << aa.toRotationMatrix() << endl;
    t1 = aa;
    t2 = aa;
    Eigen::Affine3d t3;
    t3 = aa;
    Eigen::Translation3d t4;
    t4 = Eigen::Translation3d(1, 0, 0);
    cout << " t1 : Isometric transformation 3d (self defined) : \n" << t1.matrix() << endl;
    cout << " t2 : Isometric transformation 3d : \n " << t2.matrix() << endl;
    cout << " t3 : Affine transformation 3d : \n" << t3.matrix() << endl;
    cout << " t3.linear() : Affine transformation 3d : \n" << t3.linear() << endl;
    cout << " Identity isometry : \n " << Eigen::Isometry3d::Identity().matrix() << endl;
    cout << " Identity isometry (linear) : \n " << Eigen::Isometry3d::Identity().linear() << endl;
}

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
