cmake_minimum_required(VERSION 3.10)

project(Eigen_examples)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)
if(${GTest_FOUND})
    message(STATUS "GTEST FOUND: ${GTest_VERSION}")
endif()

find_package(Eigen3 REQUIRED)
include_directories(
    ${Eigen_INCLUDE_DIRS}
    ${GTest_INCLUDE_DIRS}
)
add_executable(eigen_addon ./src/eigen_addon_example.cpp)
add_definitions(-DEIGEN_MATRIXBASE_PLUGIN="/home/jagatpreet/workspaces/github/programming_ws/libraries/eigen_examples/src/MatrixBaseAddons.h")
target_link_libraries(eigen_addon Eigen3::Eigen)
add_executable(interface_with_buffer ./src/eigen_with_raw_buffer.cpp)
target_link_libraries(interface_with_buffer Eigen3::Eigen)

add_executable(test_eigen_geometry ./src/test_eigen_geometry.cpp)
target_link_libraries(test_eigen_geometry GTest::Main)

add_executable(eigen_basic_ops ./src/eigen_basic_ops.cpp)
target_link_libraries(eigen_basic_ops Eigen3::Eigen)
