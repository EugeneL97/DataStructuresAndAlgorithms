#pragma once

template <typename T>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();

    void push(T value);
    void pop();
    T peek() const;
    size_t size() const;
    bool isEmpty() const;
    void clear();



private:
    std::vector<T> heap;
    void heapifyUp();
    void heapifyDown();
};

template<typename T>
PriorityQueue<T>::PriorityQueue() = default;

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    heap.clear();
}

template <typename T>
void PriorityQueue<T>::push(T value) {
    heap.push_back(value);
    heapifyUp();
}

template <typename T>
void PriorityQueue<T>::pop() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    if (heap.size() == 1) {
        heap.pop_back();
        return;
    }
    std::swap(heap[0], heap.back());
    heap.pop_back();
    heapifyDown();
}

template<typename T>
void PriorityQueue<T>::heapifyUp() {
    if (heap.size() <= 1) {
        return;
    }

    size_t idx = heap.size() - 1;

    while (idx > 0) {
        size_t parentIdx = (idx - 1) / 2;
        if (heap[idx] >= heap[parentIdx]) {
            break;
        }
        std::swap(heap[idx], heap[parentIdx]);
        idx = parentIdx;
    }
}

template<typename T>
void PriorityQueue<T>::heapifyDown() {
    if (heap.size() <= 1) {
        return;
    }

    size_t idx = 0;

    while (true) {
        size_t left_child = idx * 2 + 1;
        size_t right_child = idx * 2 + 2;

        // If no children exist, we're done
        if (left_child >= heap.size()) {
            break;
        }

        size_t smallest = idx;

        // Compare with left child
        if (heap[left_child] < heap[smallest]) {
            smallest = left_child;
        }

        // Compare with right child (only if it exists)
        if (right_child < heap.size() && heap[right_child] < heap[smallest]) {
            smallest = right_child;
        }

        // If no swap is needed, we're done
        if (smallest == idx) {
            break;
        }

        std::swap(heap[idx], heap[smallest]);
        idx = smallest; // Move down the tree
    }
}

template <typename T>
T PriorityQueue<T>::peek() const{
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}
template <typename T>
size_t PriorityQueue<T>::size() const {
    return heap.size();
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return heap.empty();
}

template<typename T>
void PriorityQueue<T>::clear() {
    // Check if this actually works with std::vector.clear()
    heap.clear();
}


