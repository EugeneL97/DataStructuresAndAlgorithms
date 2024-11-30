#include <gtest/gtest.h>
#include "../Queue/PriorityQueue.h"
#include <random>

class PriorityQueueTest : public ::testing::Test {
protected:
    PriorityQueue<int> priorityQueue;

    template<typename T>
    bool isValidMinHeap(PriorityQueue<T> pq) {
        // Empty heap is always valid
        if (pq.isEmpty()) {
            return true;
        }

        T lastValue = pq.peek();
        pq.pop();

        // Confirm all elements are in non-decreasing order
        while (!pq.isEmpty()) {
            T currentValue = pq.peek();

            // If elements are in decreasing order, heap property is violated
            if (currentValue < lastValue) {
                return false;
            }
            lastValue = currentValue;
            pq.pop();
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
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 10000);
    for (size_t i = 0; i < 100; ++i) {
        priorityQueue.push(dist(gen));
    }
    for (size_t i = 0; i < 30; ++i) {
        priorityQueue.pop();
    }

    EXPECT_TRUE(isValidMinHeap(priorityQueue));
}

TEST_F(PriorityQueueTest, HeapPropertyMaintainedWithDuplicates) {

    for (size_t i = 0; i < 10; ++i) {
        priorityQueue.push(10);
    }

    EXPECT_TRUE(isValidMinHeap(priorityQueue));
}

TEST_F(PriorityQueueTest, PushNegativeValues) {
    for (int i = 0; i < 10; ++i) {
        priorityQueue.push((i + 1) * -1);
    }
    EXPECT_TRUE(isValidMinHeap(priorityQueue));
}

TEST_F(PriorityQueueTest, PushZeroValue) {
    for (int i = 0; i < 10; ++i) {
        priorityQueue.push((0));
    }
    EXPECT_TRUE(isValidMinHeap(priorityQueue));
}

TEST_F(PriorityQueueTest, PopUntilEmpty) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 10000);
    for (size_t i = 0; i < 100; ++i) {
        priorityQueue.push(dist(gen));
    }
    for (size_t i = 0; i < 100; ++i) {
        priorityQueue.pop();
    }
    ASSERT_TRUE(priorityQueue.isEmpty());
    ASSERT_EQ(priorityQueue.size(), 0);
}

TEST_F(PriorityQueueTest, PushAndPopInterweaved) {
    for (int i = 0; i < 20; ++i) {
        priorityQueue.push(i);
        if (i % 3 == 0) {
            priorityQueue.pop();
        }
    }
    ASSERT_FALSE(priorityQueue.isEmpty());
    ASSERT_TRUE(isValidMinHeap(priorityQueue));

    while (!priorityQueue.isEmpty()) {
        priorityQueue.pop();
    }

    // Ensure it's empty after clearing
    ASSERT_TRUE(priorityQueue.isEmpty());
}

TEST_F(PriorityQueueTest, PushLargeNumberOfElements) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 10000);

    for (int i = 0; i < 100000; ++i) {
        priorityQueue.push(dist(gen)); // Insert random values
    }
}

TEST_F(PriorityQueueTest, PopLargeNumberofElements) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 10000);

    for (int i = 0; i < 100000; ++i) {
        priorityQueue.push(dist(gen)); // Insert random values
    }

    while(!priorityQueue.isEmpty()) {
        priorityQueue.pop();
    }

    EXPECT_TRUE(priorityQueue.isEmpty());
}

TEST_F(PriorityQueueTest, PushAndPopLargeInterweaving) {
    for (int i = 0; i < 100000; ++i) {
        priorityQueue.push(i);
        if (i % 2 == 0) {
            priorityQueue.pop();
        }
    }
    EXPECT_TRUE(isValidMinHeap(priorityQueue));
}

TEST_F(PriorityQueueTest, ClearHeap) {
    for (int i = 0; i < 10; ++i) {
        priorityQueue.push((i + 1) * -1);
    }
    priorityQueue.clear();
    EXPECT_TRUE(priorityQueue.isEmpty());
}

TEST_F(PriorityQueueTest, IsEmptyReturnsTrueOnEmptyHeap) {
    EXPECT_TRUE(priorityQueue.isEmpty());
}

TEST_F(PriorityQueueTest, SizeAfterPushesAndPops) {
    priorityQueue.push(1);
    priorityQueue.pop();
    priorityQueue.push(2);
    priorityQueue.push(3);
    priorityQueue.pop();

    EXPECT_EQ(priorityQueue.size(), 1);
}