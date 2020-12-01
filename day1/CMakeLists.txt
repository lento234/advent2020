cmake_minimum_required (VERSION 3.10)

# use gcc 
set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_C_COMPILER "gcc-10")
set(CMAKE_VERBOSE_MAKEFILE ON)

project(day1)

# compiler flags
set(CMAKE_CXX_STANDARD 14)
# setting compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "(C|c?)lang")
    add_compile_options(-Weverything)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
add_compile_options(-O3)

add_executable(main main.cpp)
