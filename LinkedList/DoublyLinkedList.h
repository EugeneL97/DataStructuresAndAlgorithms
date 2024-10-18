//
// Created by Work on 10/18/2024.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    //TODO: Copy constructor, assignment operator

    void addFirst(const T& elem);
    void addLast(const T& elem);
    void addAt(int index, const T& elem);

    T& peekFirst() const;
    T peekLast() const;

    T removeFirst();
    T removeLast();
    T removeAt(int index);
    bool remove(const T& elem);

    int indexOf(const T& elem) const;
    bool contains(const T& elem) const;

    void clear();
    int size() const;
    bool isEmpty() const;
    void printList() const;

private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node(const T& elem, Node *n = nullptr, Node *p = nullptr)
        : data(elem), next(n), prev(p) {}
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {

}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {

}


template<typename T>
void DoublyLinkedList<T>::addFirst(const T &elem) {
}

template<typename T>
void DoublyLinkedList<T>::addLast(const T &elem) {
}

template<typename T>
void DoublyLinkedList<T>::addAt(int index, const T &elem) {
}

template<typename T>
T & DoublyLinkedList<T>::peekFirst() const {
}

template<typename T>
T DoublyLinkedList<T>::peekLast() const {
}

template<typename T>
T DoublyLinkedList<T>::removeFirst() {
}

template<typename T>
T DoublyLinkedList<T>::removeLast() {
}

template<typename T>
T DoublyLinkedList<T>::removeAt(int index) {
}

template<typename T>
bool DoublyLinkedList<T>::remove(const T &elem) {
}

template<typename T>
int DoublyLinkedList<T>::indexOf(const T &elem) const {
}

template<typename T>
bool DoublyLinkedList<T>::contains(const T &elem) const {
}

template<typename T>
void DoublyLinkedList<T>::clear() {
}

template<typename T>
int DoublyLinkedList<T>::size() const {
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
}

template<typename T>
void DoublyLinkedList<T>::printList() const {
}
#endif //DOUBLYLINKEDLIST_H
