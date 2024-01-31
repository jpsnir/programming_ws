project(leet-code)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
find_package(Eigen3 REQUIRED)
find_package(GTest REQUIRED)
find_package(Boost REQUIRED COMPONENTS iostreams system filesystem)
add_library(gnuplot_iostream INTERFACE)
target_include_directories(gnuplot_iostream INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
    $<INSTALL_INTERFACE:>)
target_link_libraries(gnuplot_iostream INTERFACE
    Boost::iostreams
    Boost::system
    Boost::filesystem
)
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
add_executable(remove_duplicates
                ./src/remove_duplicates.cpp)
add_executable(problem_1 ./src/p1_two_sum.cpp)
add_executable(problem_2 ./src/p2_add_two_numbers.cpp)
add_executable(reverse_stack_recursion ./src/stack_reverse.cpp)
add_executable(mergable_stack ./src/mergable_stack.cpp)
add_executable(prefix_to_infix ./src/prefix_to_infix.cpp)
add_executable(network_occupancy_probability
    ./src/network_traffic_probability_distribution.cpp)
add_executable(recursion_vs_loop ./src/recursion_vs_loop.cpp)
add_executable(monte_carlo_integrator ./src/monte_carlo_integrator.cpp)
add_executable(rk4_integration ./src/rk4_method.cpp)
add_executable(tree_ds ./src/trees/tree_ds.cpp)
add_executable(tree_travesal ./src/trees/tree_access.cpp)
add_executable(tree_depth ./src/trees/tree_depth.cpp)
#add_executable(chair_allocation ./src/backtracking/allocate_chair_to_students.cpp)
add_executable(min_max ./src/recursion/min_max.cpp)
add_executable(compute_power ./src/recursion/power_number.cpp)
add_executable(multistage_graph_cost ./src/dynamic_programming/multistage_graph.cpp)
add_executable(fibonacci_memoization
    ./src/dynamic_programming/fibonacci.cpp)
add_executable(queue_using_array
    ./src/queue/queue_using_arrays.cpp)
add_executable(queue_using_list
    ./src/queue/queue_using_linked_list.cpp)
add_executable(flood_fill ./src/trees/flood_fill.cpp)
add_executable(climbing_stairs ./src/dynamic_programming/climbing_stairs.cpp)
add_executable(maximum_rob ./src/dynamic_programming/house_robber.cpp)
add_executable(minimum_climbing_cost
    ./src/dynamic_programming/min_climbing_cost.cpp)
target_link_libraries(network_occupancy_probability gnuplot_iostream)


add_executable(graph_bfs ./src/graph_bfs.cpp)
add_executable(graph_node_level ./src/graph_node_level.cpp)
