#include <gtest/gtest.h>       // Google Test header
#include "../Array/DynamicArray.h"  // Adjust the path if necessary

#include <gtest/gtest.h>
#include "../Array/DynamicArray.h"  // Adjust the path if needed

// Test fixture to set up and tear down DynamicArray objects for tests
class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> array{2};

    // Runs before each test
    void SetUp() override {

    }
};

// Test: Check that the array is initially empty
TEST_F(DynamicArrayTest, InitialArrayIsEmpty) {
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_TRUE(array.isEmpty());
}

// Test: Append elements and verify size
TEST_F(DynamicArrayTest, AppendIncreasesSize) {
    array.append(10);
    array.append(20);
    EXPECT_EQ(array.getSize(), 2);
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array[1], 20);
}

// Test: Automatic resizing when capacity is exceeded
TEST_F(DynamicArrayTest, ResizesWhenCapacityExceeded) {
    array.append(1);
    array.append(2);
    array.append(3);  // Triggers resizing
    EXPECT_EQ(array.getSize(), 3);
    EXPECT_EQ(array.getCapacity(), 4);  // Initial capacity doubled to 4
}

// Test: Remove an element and verify the size decreases
TEST_F(DynamicArrayTest, RemoveElementDecreasesSize) {
    array.append(10);
    array.append(20);
    array.removeAt(0);  // Remove the first element
    EXPECT_EQ(array.getSize(), 1);
    EXPECT_EQ(array[0], 20);  // Check that the second element shifted to index 0
}

// Test: Accessing an out-of-bounds index throws an exception
TEST_F(DynamicArrayTest, AccessOutOfBoundsThrows) {
    EXPECT_THROW(array.getAt(0), std::out_of_range);  // Array is empty, index 0 is invalid

    array.append(42);
    EXPECT_NO_THROW(array.getAt(0));  // This should not throw
    EXPECT_THROW(array.getAt(1), std::out_of_range);  // Index 1 is invalid (only one element)
}

// Test: Clear the array and check that it becomes empty
TEST_F(DynamicArrayTest, ClearEmptiesArray) {
    array.append(10);
    array.append(20);
    array.clear();
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_TRUE(array.isEmpty());
}

// Test: Set an element at a valid index
TEST_F(DynamicArrayTest, SetElementWorks) {
    array.append(5);
    array.setAt(0, 42);
    EXPECT_EQ(array[0], 42);
}

