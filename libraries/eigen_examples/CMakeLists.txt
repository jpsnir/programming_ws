cmake_minimum_required(VERSION 3.10)

project(Eigen_examples)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Eigen3 REQUIRED)
add_executable(eigen_addon ./src/eigen_addon_example.cpp)
add_definitions(-DEIGEN_MATRIXBASE_PLUGIN="/home/jagatpreet/workspaces/github/programming_ws/libraries/eigen_examples/src/MatrixBaseAddons.h")
target_link_libraries(eigen_addon Eigen3::Eigen)
add_executable(interface_with_buffer ./src/eigen_with_raw_buffer.cpp)
target_link_libraries(interface_with_buffer Eigen3::Eigen)
