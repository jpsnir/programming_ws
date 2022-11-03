project(leet-code)
cmake_minimum_required(VERSION 3.1)

find_package(Eigen3 REQUIRED)
find_package(GTest REQUIRED)
if (Eigen_FOUND)
    message("Eigen Package Found:" ${Eigen_INCLUDE_DIRS})
endif()
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(subsequence
               ${PROJECT_SOURCE_DIR}/src/subsequence.cpp)
add_executable(integer_palindrome
               ./src/integer_palindrome.cpp)
add_executable(roman_to_number
               ./src/roman_to_num.cpp)

add_executable(longest_common_prefix 
               ./src/longest_common_prefix.cpp)
add_executable(valid_paranthesis 
               ./src/valid_paranthesis.cpp)
add_executable(merge_two_lists
               ./src/merge_sorted_lists.cpp)
