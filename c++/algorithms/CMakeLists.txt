find_package(Ceres REQUIRED)

if(Ceres_FOUND)
    message("Ceres directory FOUND")
else()
    message("Ceres NOT FOUND")
endif()
set(algorithms_INCLUDE_DIRS
        include/algorithm_base.h)
set(algorithms_SRCS
        algorithms_app.cpp)
include_directories(${algorithms_INCLUDE_DIRS})

add_executable(algorithms_app
        algorithms_app.cpp)
