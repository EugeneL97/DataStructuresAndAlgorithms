#include <gtest/gtest.h>
#include "../Queue/Queue.h"

class QueueTest : public ::testing::Test {
protected:
    Queue<int> queue;

    void SetUp() override {

    }
};

TEST_F(QueueTest, InitialQueueIsEmpty) {
    EXPECT_EQ(queue.getSize(), 0);
    EXPECT_TRUE(queue.isEmpty());
}

TEST_F(QueueTest, PushToQueue) {
    queue.enqueue(5);
    EXPECT_EQ(queue.getSize(), 1);
    EXPECT_FALSE(queue.isEmpty());

    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i);
    }
    EXPECT_EQ(queue.getSize(), 11);

}

TEST_F(QueueTest, PushSingleAndPop) {
    queue.enqueue(42);
    EXPECT_EQ(queue.peek(), 42);
    queue.dequeue();
    EXPECT_TRUE(queue.isEmpty());
}

TEST_F(QueueTest, StressTest) {
    constexpr int largeSize = 1000000;
    for (int i = 0; i < largeSize; ++i) {
        queue.enqueue(i);
    }
    EXPECT_EQ(queue.getSize(), largeSize);

    for (int i = 0; i < largeSize; ++i) {
        EXPECT_EQ(queue.peek(), i);
        queue.dequeue();
    }
    EXPECT_TRUE(queue.isEmpty());
}

TEST_F(QueueTest, PopFromQueue) {
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i*i*i);
    }
    EXPECT_EQ(queue.getSize(), 10);

    queue.dequeue();
    EXPECT_EQ(queue.getSize(), 9);
    const int counter = queue.getSize();
    for (int i = 0; i < counter; ++i) {
        queue.dequeue();
    }

    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.getSize(), 0);
}

TEST_F(QueueTest, PeekQueue) {
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i*2);
    }

    EXPECT_EQ(queue.peek(), 0);
    queue.dequeue();

    EXPECT_EQ(queue.peek(), 2);
}

TEST_F(QueueTest, PeekEmptyQueueThrows) {
    EXPECT_THROW(queue.peek(), std::out_of_range);
}

TEST_F(QueueTest, RemoveFromEmptyQueue) {
    EXPECT_THROW(queue.dequeue(), std::out_of_range);
    EXPECT_EQ(queue.getSize(), 0);
}

struct CustomData {
    int id;
    std::string name;
};

TEST_F(QueueTest, CustomDataType) {
    Queue<CustomData> customQueue;
    customQueue.enqueue({1, "Jesse"});
    customQueue.enqueue({2, "Walter"});

    EXPECT_EQ(customQueue.peek().name, "Jesse");
    customQueue.dequeue();
    EXPECT_EQ(customQueue.peek().name, "Walter");
}