//
// Created by Work on 10/18/2024.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList {
public:
    template <typename T>
    class Iterator {
    public:
        Iterator(typename DoublyLinkedList<T>::Node* node) : current(node) {}

        T& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

    private:
        typename DoublyLinkedList<T>::Node* current;
    };

    Iterator<T> begin() const {
        return Iterator(head);
    }

    Iterator<T> end() const {
        return Iterator(nullptr);
    }

    DoublyLinkedList();
    ~DoublyLinkedList();

    //TODO: Copy constructor, assignment operator

    void addFirst(const T& elem);
    void addLast(const T& elem);
    void addAt(int index, const T& elem);

    T& peekFirst() const;
    T& peekLast() const;

    T removeFirst();
    T removeLast();
    T removeAt(int index);
    bool remove(const T& elem);

    int indexOf(const T& elem) const;
    bool contains(const T& elem) const;

    void clear();
    int getSize() const;
    bool isEmpty() const;
    void printList() const;


private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& elem, Node *n = nullptr, Node *p = nullptr)
        : data(elem), next(n), prev(p) {}
    };


    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    friend class Iterator;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() = default;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}


template<typename T>
void DoublyLinkedList<T>::addFirst(const T &elem) {
    Node* newNode = new Node(elem, head, nullptr);
    if (isEmpty()) {
        tail = newNode;
    }
    else {
        head->prev = newNode;
    }
    head = newNode;
    ++size;
}

template<typename T>
void DoublyLinkedList<T>::addLast(const T &elem) {
    Node* newNode = new Node(elem, nullptr, tail);
    if (isEmpty()) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
    ++size;
}

template<typename T>
void DoublyLinkedList<T>::addAt(int index, const T &elem) {
    for (auto it = begin();)
}

template<typename T>
T& DoublyLinkedList<T>::peekFirst() const {
    return head->data;
}

template<typename T>
T& DoublyLinkedList<T>::peekLast() const {
    return tail->data;
}

template<typename T>
T DoublyLinkedList<T>::removeFirst() {
    --size;
}

template<typename T>
T DoublyLinkedList<T>::removeLast() {
    --size;
}

template<typename T>
T DoublyLinkedList<T>::removeAt(int index) {
    --size;
}

template<typename T>
bool DoublyLinkedList<T>::remove(const T &elem) {
    --size;
}

template<typename T>
int DoublyLinkedList<T>::indexOf(const T &elem) const {
    int index = 0;
    for (auto it = begin(); it != end(); ++it, ++index) {
        if (*it == elem) {
            return index;
        }
    }
    return -1;
}

template<typename T>
bool DoublyLinkedList<T>::contains(const T &elem) const {
    for (auto it = begin(); it != end(); ++it) {
        if (*it == elem) {
            return true;
        }
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    for (auto it = begin(); it != end(); ++it) {
        removeFirst();
    }
    head = nullptr;
    tail = nullptr;
}

template<typename T>
int DoublyLinkedList<T>::getSize() const {
    return size;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    if (size == 0) {
        return true;
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::printList() const {
    for (auto it = begin(); it != end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
#endif //DOUBLYLINKEDLIST_H
