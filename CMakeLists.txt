cmake_minimum_required(VERSION 3.27)
project(DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructures
        main.cpp
        Array/DynamicArray.h
        LinkedList/DoublyLinkedList.h
        Stack/Stack.h
        Queue/Queue.h
        Queue/PriorityQueue.h)

# GTest Support
enable_testing()
add_subdirectory(googletest)

# Tests for each Data Structure
add_executable(dynamic_array_test
        tests/test_dynamic_array.cpp
        Array/DynamicArray.h)

add_executable(linked_list_test
        tests/test_linked_list.cpp
        LinkedList/DoublyLinkedList.h)

add_executable(stack_test
        tests/test_stack.cpp
        Stack/Stack.h)

add_executable(queue_test
        tests/test_queue.cpp
        Queue/Queue.h)

add_executable(priority_queue_test
        tests/test_priority_queue.cpp
        Queue/PriorityQueue.h)

# Link GTest
target_link_libraries(dynamic_array_test gtest gtest_main)
target_link_libraries(linked_list_test gtest gtest_main)
target_link_libraries(stack_test gtest gtest_main)
target_link_libraries(queue_test gtest gtest_main)
target_link_libraries(priority_queue_test gtest gtest_main)

# Register the test with CMake
add_test(NAME DynamicArrayTest COMMAND dynamic_array_test)
add_test(NAME LinkedListTest COMMAND linked_list_test)
add_test(NAME StackTest COMMAND stack_test)
add_test(NAME QueueTest COMMAND queue_test)
add_test(NAME PriorityQueueTest COMMAND priority_queue_test)