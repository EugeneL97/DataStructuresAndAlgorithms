//
// Created by Work on 10/15/2024.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T>
class DynamicArray {
    private:
        T *data;
        int size;
        int capacity;
        const int decreaseSizeThreshold = 0.25;
        void resize(int newCapacity);

    public:
        DynamicArray(int initialCapacity = 2);
        ~DynamicArray();

        T& operator[](int index);
        T& getAt(int index);

        void append(T value);
        void increaseSizeCheck();

        void removeAt(int index);
        void decreaseSizeCheck();
        T getAt(int index) const;

        void setAt(int index, T value);
        void indexBoundsCheck(int index) const;
        void clear();

        bool isEmpty() const;
        int getCapacity() const;
        int getSize() const;



};
#endif //DYNAMICARRAY_H
