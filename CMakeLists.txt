cmake_minimum_required(VERSION 3.29)
project(DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructures main.cpp
        Array/DynamicArray.cpp
        Array/DynamicArray.h)
