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
    heap.heapifyUp();
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
    heap.heapifyDown();
}

template<typename T>
void PriorityQueue<T>::heapifyUp() {
    // Empty heaps or single element heaps that never require swapping
    if (heap.size() <= 1) {
        return;
    }

    size_t idx = heap.size() - 1;
    size_t parentIdx = (idx - 1) / 2;

    while (idx > 0 && heap[idx] < heap[parentIdx]) {
        std::swap(heap[idx], heap[parentIdx]);
        idx = parentIdx;
        parentIdx = (parentIdx - 1) / 2;
    }
}

template<typename T>
void PriorityQueue<T>::heapifyDown() {
    // Empty heaps or single element heaps that never require swapping
    if (heap.size() <= 1) {
        return;
    }

    size_t idx = 0;
    size_t left_child = idx * 2 + 1;
    size_t right_child = idx * 2 + 2;

    while (left_child < heap.size()) {
        if (right_child < heap.size()) {
            // Swap with the smaller child to maintain the min-heap property
            if (heap[left_child] <= heap[right_child]) {
                std::swap(heap[idx], heap[left_child]);
                idx = left_child;
            }
            else {
                std::swap(heap[idx], heap[right_child]);
                idx = right_child;
            }
        }
        else {
            if (heap[idx] > heap[left_child]) {
                std::swap(heap[idx], heap[left_child]);
            }
            idx = left_child;
        }
        left_child = idx * 2 + 1;
        right_child = idx * 2 + 2;
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


