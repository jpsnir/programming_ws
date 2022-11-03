project("paramter_server")
cmake_minimum_required(VERSION 3.0.0)

find_package(roscpp REQUIRED)
if (roscpp_FOUND)
    message("roscpp FOUND :" ${roscpp_INCLUDE_DIRS})
endif()

find_package(GTest REQUIRED)

include_directories(${roscpp_INCLUDE_DIRS})
add_executable(parameter_server
               parameter_server.cpp)
target_link_libraries(parameter_server ${roscpp_LIBRARIES})
