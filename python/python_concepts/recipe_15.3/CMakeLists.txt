project(recipe_15_3)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_EXPORT_COMPILE_COMMANDS, ON)
find_package(PythonLibs REQUIRED)
if (PythonLibs_FOUND)
 message("Python found")
endif()

add_library(sample SHARED sample.c)
target_include_directories(sample PUBLIC include)
target_link_libraries(sample m)

add_executable(testSample ./testLibSample.c)
target_link_libraries(testSample sample)

add_library(pysample ./pysample.c)
target_link_libraries(pysample ${PYTHON_LIBRARIES})
target_include_directories(pysample ${PYTHON_INCLUDE_DIRS})
