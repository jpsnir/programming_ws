#cmake_minimum_required(VERSION 3.2)
#project(C++_concepts)

find_package(Eigen3 3.3 REQUIRED)
if(${Eigen3_FOUND})
    message("Eigen 3 include directory is:" ${EIGEN3_INCLUDE_DIRS})
else()
    message("Eigen 3 not found")
endif()

set(eigen_concepts_SRCS apps/hello_eigen.cpp)
set(eigen_concepts_INCLUDE_DIRS include/)
include_directories(${eigen_concepts_INCLUDE_DIRS})
add_executable(eigen_examples ${eigen_concepts_SRCS})

target_link_libraries(eigen_examples)