cmake_minimum_required(VERSION 3.27)
project(DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructures
        main.cpp
        Array/DynamicArray.h)

# GTest Support
enable_testing()
add_subdirectory(googletest)

add_executable(dynamic_array_test
        tests/test_dynamic_array.cpp
        Array/DynamicArray.h)

# Link GTest
target_link_libraries(dynamic_array_test gtest gtest_main)

# Register the test with CMake
add_test(NAME DynamicArrayTest COMMAND dynamic_array_test)