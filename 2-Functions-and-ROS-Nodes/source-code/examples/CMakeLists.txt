#define the version of CMake you are using here 3.1
cmake_minimum_required(VERSION 3.1)
#project name
project(first_project)

#C++ version in use, here 17

set(CMAKE_CXX_STANDARD 17)

#add executable main, this creates main.o
add_executable(ex1 src/ex1.cpp)
add_executable(ex2 src/ex2.cpp)
add_executable(ex3 src/ex3.cpp)
add_executable(ex4 src/ex4.cpp)
add_executable(ex5 src/ex5.cpp)
add_executable(ex6 src/ex6.cpp)