#pragma once

#include "../LinkedList/DoublyLinkedList.h"

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(T value);
    void dequeue();
    T peek() const;
    bool contains(T value);

    int getSize() const;
    bool isEmpty() const;


private:
    DoublyLinkedList<T> queue;
};

template <typename T>
Queue<T>::Queue() = default;

template <typename T>
Queue<T>::~Queue() {
    queue.clear();
}

template <typename T>
void Queue<T>::enqueue(T value) {
    queue.addLast(value);
}

template <typename T>
void Queue<T>::dequeue() {
    queue.removeFirst();
}

template <typename T>
T Queue<T>::peek() const{
    return queue.peekFirst();
}

template <typename T>
bool Queue<T>::contains(T value) {
    return queue.contains(value);
}

template<typename T>
int Queue<T>::getSize() const {
    return queue.getSize();
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return queue.isEmpty();
}



