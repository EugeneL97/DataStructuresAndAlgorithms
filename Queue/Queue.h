#pragma once

#include "../LinkedList/DoublyLinkedList.h"

template <typename T>
class Deque {
public:
    Deque();
    ~Deque();

    void enqueue_left(T value);
    void enqueue_right(T value);
    void dequeue_left();
    void dequeue_right();
    void
    T front() const;

private:
    DoublyLinkedList<T> deque;
};