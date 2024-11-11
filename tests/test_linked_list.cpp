#include <gtest/gtest.h>
#include "../LinkedList/DoublyLinkedList.h"

class LinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedList<int> list;

    void SetUp() override {

    }
};

TEST_F(LinkedListTest, InitialListIsEmpty) {
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.isEmpty());
}

TEST_F(LinkedListTest, AddToEmptyList) {
    list.addFirst(10);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.peekFirst(), 10);
    list.removeFirst();

    list.addLast(20);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.peekLast(), 20);
    list.removeLast();

    list.addAt(0, 15);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.indexOf(15), 0);
    list.removeAt(0);
}

TEST_F(LinkedListTest, RemoveFromEmptyList) {
    EXPECT_THROW(list.removeFirst(), std::out_of_range);
    EXPECT_EQ(list.getSize(), 0);

    EXPECT_THROW(list.removeLast(), std::out_of_range);
    EXPECT_EQ(list.getSize(), 0);

    EXPECT_THROW(list.removeAt(0), std::out_of_range);
    EXPECT_EQ(list.getSize(), 0);
}

TEST_F(LinkedListTest, AccessEmptyList) {
    EXPECT_TRUE(list.isEmpty());
}


TEST_F(LinkedListTest, RemoveDecreasesSize) {
    for (int i = 0; i < 10; ++i) {
        list.addFirst(1 * i);
    }
    EXPECT_EQ(list.getSize(), 10);

    list.remove(5);
    EXPECT_EQ(list.getSize(), 9);

    list.removeFirst();
    EXPECT_EQ(list.getSize(), 8);

    list.removeLast();
    EXPECT_EQ(list.getSize(), 7);

    list.clear();
    EXPECT_EQ(list.getSize(), 0);
}

