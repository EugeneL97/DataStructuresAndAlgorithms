//
// Created by Work on 10/15/2024.
//

#include "DynamicArray.h"
#include <stdexcept>

template<typename T>
DynamicArray<T>::DynamicArray(int initialCapacity) {
    data = new T[initialCapacity];
    size = 0;
    capacity = initialCapacity;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
T& DynamicArray<T>::operator[](int index){
    return getAt(index);
}

template<typename T>
T& DynamicArray<T>::getAt(int index) {
    indexBoundsCheck(index);
    return data[index];
}
template<typename T>
void DynamicArray<T>::append(T value) {
    increaseSizeCheck();
    data[size++] = value;
}
template<typename T>
void DynamicArray<T>::increaseSizeCheck() {
    if (size == capacity) {
        T* newData = new T[capacity * 2];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity *= 2;
    }
}


template<typename T>
void DynamicArray<T>::removeAt(int index) {
    indexBoundsCheck(index);
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template<typename T>
void DynamicArray<T>::decreaseSizeCheck() {
    if (size <= capacity * decreaseSizeThreshold) {
        T* newData = new T[capacity * (decreaseSizeThreshold * 2)];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity *= (decreaseSizeThreshold * 2);
    }
}

template<typename T>
T DynamicArray<T>::getAt(int index) const {
    indexBoundsCheck(index);
    return data[index];
}

template<typename T>
void DynamicArray<T>::setAt(int index, T value) {
    indexBoundsCheck(index);
    data[index] = value;
}

template<typename T>
void DynamicArray<T>::indexBoundsCheck(int index) const{
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range!");
    }
}

template<typename T>
void DynamicArray<T>::clear() {
    size = 0;
}

template<typename T>
bool DynamicArray<T>::isEmpty() const{
    if (size == 0) {
        return true;
    }
    return false;
}

template<typename T>
int DynamicArray<T>::getCapacity() const {
    return capacity;
}

template<typename T>
int DynamicArray<T>::getSize() const {
    return size;
}
