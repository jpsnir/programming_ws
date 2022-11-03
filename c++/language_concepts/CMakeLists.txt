project(language_concepts)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug/)
find_package(Boost REQUIRED)
find_package(GTest REQUIRED)
if (GTEST_FOUND)
    message(" Gtest found : " ${GTEST_INCLUDE_DIRS})
endif()

add_subdirectory(${PROJECT_SOURCE_DIR}/src/chapter3)
add_executable(heap_understanding ./src/heap_understanding.cpp)


