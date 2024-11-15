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

TEST_F(StackTest, RemoveFromStack) {
    for (int i = 0; i < 10; ++i) {
        stack.add(i*i*i);
    }
    EXPECT_EQ(stack.getSize(), 10);

    stack.pop();
    EXPECT_EQ(stack.getSize(), 9);

    for (int i = 0; i < stack.getSize(); ++i) {
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