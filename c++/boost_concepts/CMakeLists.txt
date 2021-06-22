

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED filesystem regex serialization system)

if(Boost_FOUND)
    message(" Boost FOUND")
    message("Boost include directories:" ${Boost_INCLUDE_DIRS})
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message("Boost not found")
endif()

set(boost_concepts_SRCS apps)
set(boost_concepts_INCLUDE_DIRS include)


include_directories(${boost_concepts_INCLUDE_DIRS})
add_executable(boost_archive_demo ${boost_concepts_SRCS}/boost_archive.cpp)

target_link_libraries(boost_archive_demo ${Boost_LIBRARIES})