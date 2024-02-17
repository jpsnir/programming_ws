#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
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

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}