cmake_minimum_required(VERSION 3.10)
project(pybind_examples)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(Eigen3 REQUIRED)
find_package(pybind11 CONFIG REQUIRED
    PATHS
    "/home/jagatpreet/.local/lib/python3.8/site-packages/pybind11")
if(pybind11_FOUND)
    message(STATUS "pybind 11 found - ${pybind11_INCLUDE_DIRS}")
endif()

pybind11_add_module(example ./src/hello_pybind.cpp)
target_link_libraries(example PUBLIC Eigen3::Eigen)

#add_library(example1 MODULE ./src/hello_pybind.cpp)
#target_link_libraries(example1 PUBLIC pybind11::module)
