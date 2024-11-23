#include <gtest/gtest.h>
#include "../Queue/PriorityQueue.h"
#include <random>

class PriorityQueueTest : public ::testing::Test {
protected:
    PriorityQueue<int> priorityQueue;

    template<typename T>
    bool isValidMinHeap(const PriorityQueue<T> heap) {
        for (size_t i = 0; i < heap.size(); ++i) {
            size_t left_child = 2 * i + 1;
            size_t right_child = 2 * i + 2;

            if (left_child < heap.size() && heap[i] > heap[left_child]) {
                return false; // Min-heap violated
            }

            if (right_child < heap.size() && heap[i] > heap[right_child]) {
                return false; // Min-heap violated
            }
        }
        return true;
    }

    void SetUp() override {

    }
};

TEST_F(PriorityQueueTest, EmptyHeapPeekThrowsException) {
    EXPECT_THROW(priorityQueue.peek(), std::runtime_error);
}

TEST_F(PriorityQueueTest, EmptyHeapPopThrowsException) {
    EXPECT_THROW(priorityQueue.pop(), std::runtime_error);
}

TEST_F(PriorityQueueTest, PushSingleElement) {
    priorityQueue.push(5);
    EXPECT_EQ(priorityQueue.peek(), 5);
}

TEST_F(PriorityQueueTest, PopSingleElement) {
    priorityQueue.push(5);
    priorityQueue.push(10);

    priorityQueue.pop();

    EXPECT_EQ(priorityQueue.peek(), 10);
}

TEST_F(PriorityQueueTest, PeekSingleElement) {
    priorityQueue.push(26);

    EXPECT_EQ(priorityQueue.peek(), 26);
}

TEST_F(PriorityQueueTest, HeapPropertyAfterMultiplePushes) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 10000);
    for (size_t i = 0; i < 10; ++i) {
        priorityQueue.push(dist(gen));
    }
    EXPECT_TRUE(isValidMinHeap(priorityQueue));
}

TEST_F(PriorityQueueTest, HeapPropertyAfterMultiplePops) {

}

TEST_F(PriorityQueueTest, HeapPropertyMaintainedWithDuplicates) {

}

TEST_F(PriorityQueueTest, PushNegativeValues) {

}

TEST_F(PriorityQueueTest, PushZeroValue) {

}

TEST_F(PriorityQueueTest, PopUntilEmpty) {

}

TEST_F(PriorityQueueTest, PushAndPopInterweaved) {

}

TEST_F(PriorityQueueTest, PushLargeNumberOfElements) {

}

TEST_F(PriorityQueueTest, PopLargeNumberofElements) {

}

TEST_F(PriorityQueueTest, PushAndPopLargeInterweaving) {

}

TEST_F(PriorityQueueTest, ClearHeap) {

}

TEST_F(PriorityQueueTest, IsEmptyReturnsTrueOnEmptyHeap) {

}

TEST_F(PriorityQueueTest, SizeAfterPushesAndPops) {

}