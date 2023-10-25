cmake_minimum_required(VERSION 3.10)

project(Eigen_examples)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Eigen3 REQUIRED)
add_executable(eigen_addon ./src/eigen_addon_example.cpp)
add_definitions(-DEIGEN_MATRIXBASE_PLUGIN="/home/jagatpreet/workspaces/programming_ws/libraries/eigen/src/MatrixBaseAddons.h")
target_link_libraries(eigen_addon Eigen3::Eigen)
