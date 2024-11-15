#pragma once

#include "../LinkedList/DoublyLinkedList.h"

template<typename T>
class Stack {
private:

    DoublyLinkedList<T> stack;
public:
    Stack();
    ~Stack();

    T peek() const;
    void pop();
    void push(const T& elem);
    int getSize() const;
    bool isEmpty() const;
};

template<typename T>
Stack<T>::Stack() = default;

template<typename T>
Stack<T>::~Stack() {
    stack.clear();
}
template<typename T>
T Stack<T>::peek() const{
    return stack.peekLast();
}
template<typename T>
void Stack<T>::pop() {
    stack.removeLast();
}
template<typename T>
void Stack<T>::push(const T& elem) {
    stack.addLast(elem);
}
template<typename T>
int Stack<T>::getSize() const{
    return stack.getSize();
}
template<typename T>
bool Stack<T>::isEmpty() const{
    return stack.isEmpty();
}