cmake_minimum_required(VERSION 3.15)

project(day3)

# C++17 standard
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Make it release build to add -O3 and -DNDEBUG flags
#set(CMAKE_BUILD_TYPE Release) 
set(CMAKE_BUILD_TYPE Debug) 
# also add -march-native
add_compile_options(-march=native)

# setting compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "(C|c?)lang")
    add_compile_options(-Weverything)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# add_compile_options(-O3) # optimization

# External libraries
find_package(fmt)

# Glob files
file(GLOB SOURCES "*.cpp")

# Compile binary
add_executable(main ${SOURCES})

# Link libraries
target_link_libraries(main fmt::fmt)
