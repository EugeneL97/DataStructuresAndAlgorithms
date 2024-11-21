#include <gtest/gtest.h>
#include "../Stack/Stack.h"

class StackTest : public ::testing::Test {
protected:
    Stack<int> stack;

    void SetUp() override {

    }
};

TEST_F(StackTest, InitialStackIsEmpty) {
    EXPECT_EQ(stack.getSize(), 0);
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(StackTest, PushToStack) {
    stack.push(5);
    EXPECT_EQ(stack.getSize(), 1);
    EXPECT_FALSE(stack.isEmpty());

    for (int i = 0; i < 10; ++i) {
        stack.push(i);
    }
    EXPECT_EQ(stack.getSize(), 11);

}

TEST_F(StackTest, PushSingleAndPop) {
    stack.push(42);
    EXPECT_EQ(stack.peek(), 42);
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(StackTest, StressTest) {
    constexpr int largeSize = 1000000;
    for (int i = 0; i < largeSize; ++i) {
        stack.push(i);
    }
    EXPECT_EQ(stack.getSize(), largeSize);

    for (int i = largeSize - 1; i >= 0; --i) {
        EXPECT_EQ(stack.peek(), i);
        stack.pop();
    }
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(StackTest, PopFromStack) {
    for (int i = 0; i < 10; ++i) {
        stack.push(i*i*i);
    }
    EXPECT_EQ(stack.getSize(), 10);

    stack.pop();
    EXPECT_EQ(stack.getSize(), 9);
    const int counter = stack.getSize();
    for (int i = 0; i < counter; ++i) {
        stack.pop();
    }

    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.getSize(), 0);
}

TEST_F(StackTest, PeekStack) {
    for (int i = 0; i < 10; ++i) {
        stack.push(i*2);
    }

    EXPECT_EQ(stack.peek(), 18);
    stack.pop();

    EXPECT_EQ(stack.peek(), 16);
}

TEST_F(StackTest, PeekEmptyStackThrows) {
    EXPECT_THROW(stack.peek(), std::out_of_range);
}

TEST_F(StackTest, RemoveFromEmptyStack) {
    EXPECT_THROW(stack.pop(), std::out_of_range);
    EXPECT_EQ(stack.getSize(), 0);
}

struct CustomData {
    int id;
    std::string name;
};

TEST_F(StackTest, CustomDataType) {
    Stack<CustomData> customStack;
    customStack.push({1, "Jesse"});
    customStack.push({2, "Walter"});

    EXPECT_EQ(customStack.peek().name, "Walter");
    customStack.pop();
    EXPECT_EQ(customStack.peek().name, "Jesse");
}