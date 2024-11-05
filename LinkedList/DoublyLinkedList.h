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

        typename DoublyLinkedList::Node* getNode() const {
            return current;
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

    T& peekFirst() const;
    T& peekLast() const;

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
    if (index < 0 || index > size) {
        throw std::out_of_range("Invalid index");
    }

    if (index == 0) {
        addFirst(elem);
        return;
    }

    if (index == size) {
        addLast(elem);
        return;
    }

    auto it = begin();
    for (; it != end() && index != 0; ++it, --index) {}

    Node* curr = it.current;
    Node* nodeToAdd = new Node(elem, curr, curr->prev);
    curr->prev->next = nodeToAdd;
    curr->prev = nodeToAdd;
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
    if (isEmpty()) {
        throw std::out_of_range("List is empty!");
    }
    Node* temp = head;
    Node* curr = head->next;

    temp->next = nullptr;
    T removedNode = temp->data;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;

    head = curr;
    --size;

    return removedNode;
}

template<typename T>
T DoublyLinkedList<T>::removeLast() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty!");
    }
    Node* temp = tail;
    Node* curr = tail->prev;

    temp->prev = nullptr;
    T removedNode = temp->data;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }



    delete temp;

    tail = curr;
    --size;

    return removedNode;
}

template<typename T>
T DoublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Invalid index");
    }

    if (index == 0) {
        return removeFirst();
    }

    if (index == size) {
        return removeLast();
    }

    auto it = begin();
    for(; it != end() && index != 0; ++it, --index) {}

    Node* toRemove = it.getNode();
    Node* temp = toRemove->prev;

    temp->next = toRemove->next;
    toRemove->next->prev = temp;

    T valueToRemove = toRemove->data;
    delete toRemove;
    --size;
    if (size == 0) {
        head = tail = nullptr;
    }
    return valueToRemove;
}

template<typename T>
bool DoublyLinkedList<T>::remove(const T &elem) {

    for(auto it = begin(); it != end(); ++it) {
        if (*it == elem) {
            Node* toRemove = it.current;
            Node* temp = toRemove->prev;

            temp->next = toRemove->next;
            toRemove->next->prev = temp;

            delete toRemove;
            --size;

            return true;
        }
    }
    return false;
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
    while(!isEmpty()) {
        removeFirst();
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
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
