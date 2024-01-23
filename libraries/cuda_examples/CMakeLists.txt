cmake_minimum_required(VERSION 3.10)
project(cuda_examples LANGUAGES C CXX CUDA)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# cuda
set(CUDA_HOST_COMPILER ${CMAKE_CXX_COMPILER})
set(CMAKE_CUDA_STANDARD 11)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_EXTENSIONS OFF)

# debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g")
set(CMAKE_CUDA_FLAGS_DEBUG "${CMAKE_CUDA_FLAGS} -O0 -g -lineinfo")

# find packages
find_package(Eigen3 REQUIRED)
if(${Eigen3_FOUND})
    message(STATUS " Eigen 3 found  : ${Eigen3_VERSION}")
endif()

add_executable(lin_alg_cuda ./src/lin_alg/linear_algebra.cu)
set_property(TARGET lin_alg_cuda PROPERTY CUDA_ARCHITECTURES OFF)
target_include_directories(lin_alg_cuda PUBLIC
    ${CUDA_INCLUDE_DIRS}
    ${Eigen3_INCLUDE_DIRS}
)
target_link_libraries(lin_alg_cuda PUBLIC cusolver cublas cusparse Eigen3::Eigen)

add_executable(lin_alg_eigen ./src/lin_alg/linear_algebra_eigen.cpp)
target_include_directories(lin_alg_eigen PUBLIC ${Eigen3_INCLUDE_DIRS})
target_link_libraries(lin_alg_eigen PUBLIC Eigen3::Eigen)
#target_link_libraries(lin_alg_cuda PUBLIC Eigen3::Eigen)
