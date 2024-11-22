#pragma once

#include "../LinkedList/DoublyLinkedList.h"

template <typename T>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();


private:
    DoublyLinkedList<T> priorityQueue;
};