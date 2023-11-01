cmake_minimum_required(VERSION 3.12.0)
project(linear_algebra)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
message(STATUS "${CMAKE_MODULE_PATH}")

find_package(GSL REQUIRED)
if(${GSL_FOUND})
message("Scientific library - version - " ${GSL_VERSION} "found - path" 
         ${GSL_INCLUDE_DIRS})
endif()

find_package(TBB REQUIRED)
if(${TBB_FOUND})
message( STATUS "Thread building block library found - " ${TBB_DIR})
message( STATUS "Imported targets" ${TBB_IMPORTED_TARGETS})
endif()

find_package(OpenCL REQUIRED)
if(${OpenCL_FOUND})
message(STATUS "OpenCL found : " ${OpenCL_INCLUDE_DIRS})
message(STATUS "opencl imported targets: " ${OpenCL_IMPORTED_TARGETS})
endif()

find_package(MKL REQUIRED)
message(STATUS "${MKL_IMPORTED_TARGETS}") #Provides available list of targets based on input

get_property(importTargetsAfter DIRECTORY "${CMAKE_SOURCE_DIR}" PROPERTY IMPORTED_TARGETS)
message("${importTargetsAfter}")

add_executable(gsl_basic ./gsl_basic.cpp)
target_link_libraries(gsl_basic GSL::gsl)

