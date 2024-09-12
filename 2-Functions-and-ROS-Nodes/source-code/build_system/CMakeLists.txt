#define the version of CMake you are using here 3.1
cmake_minimum_required(VERSION 3.1)
#project name
project(first_project)

#C++ version in use, here 17

set(CMAKE_CXX_STANDARD 17)

#add executable main, this creates main.o
add_executable(hello_ros src/ex0.cpp)

