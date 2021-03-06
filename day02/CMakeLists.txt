cmake_minimum_required(VERSION 3.15)

project(day02)

# C++17 standard
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Build type
set(CMAKE_BUILD_TYPE Release) # Make it release build to add -O3 and -DNDEBUG flags
#set(CMAKE_BUILD_TYPE Debug) 
add_compile_options(-march=native)

# setting compiler flags
add_compile_options(-Wall -Wextra -Wpedantic)

# External libraries
find_package(fmt)

# Glob files
file(GLOB SOURCES "src/*.cpp")

# Compile binary
add_executable(day02 ${SOURCES})

# Link libraries
target_link_libraries(day02 fmt::fmt)

# add input files
configure_file(input.txt input.txt)
configure_file(test_input.txt test_input.txt)
