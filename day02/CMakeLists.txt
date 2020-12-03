cmake_minimum_required(VERSION 3.15)

project(day2)

# compiler flags
set(CMAKE_CXX_STANDARD 17) # compiler standard
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# setting compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "(C|c?)lang")
    add_compile_options(-Weverything)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
add_compile_options(-O3) # optimization

# External libraries
find_package(fmt)

# Glob files
file(GLOB SOURCES "*.cpp")

# Compile binary
add_executable(main ${SOURCES})

# Link libraries
target_link_libraries(main fmt::fmt)
