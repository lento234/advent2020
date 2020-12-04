cmake_minimum_required(VERSION 3.15)

project(day4)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_C_COMPILER "gcc-10")
    set(CMAKE_CXX_COMPILER "g++-10")
    set(CMAKE_CXX_COMPILER_ID "GNU")
endif()

# C++17 standard
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Build type
set(CMAKE_BUILD_TYPE Release) # Make it release build to add -O3 and -DNDEBUG flags
#set(CMAKE_BUILD_TYPE Debug) 
add_compile_options(-march=native)

# setting compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "(C|c?)lang")
    add_compile_options(-Weverything)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# External libraries
find_package(fmt)

# Glob files
file(GLOB SOURCES "src/*.cpp")

# Compile binary
add_executable(main ${SOURCES})

# Link libraries
target_link_libraries(main fmt::fmt)
