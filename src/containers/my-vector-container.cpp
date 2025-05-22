#include "abstract/my-vector-container.h"
#include <stdexcept> // For std::out_of_range
#include <algorithm> // For std::sort, std::reverse

template <typename T>
MyVector<T>::MyVector() : arr(nullptr), size(0), capacity(0) {}

template <typename T>
void MyVector<T>::resize() {
    size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
    std::unique_ptr<T[]> new_arr = std::make_unique<T[]>(new_capacity);

    for (size_t i = 0; i < size; ++i) {
        new_arr[i] = std::move(arr[i]);
    }

    arr = std::move(new_arr);
    capacity = new_capacity;
}

template <typename T>
void MyVector<T>::push_back(const T& element) {
    if (size == capacity) {
        resize();
    }
    arr[size++] = element;
}

template <typename T>
void MyVector<T>::pop_back() {
    if (size > 0) {
        --size;
    }
}

template <typename T>
void MyVector<T>::clear() {
    arr.reset();
    size = 0;
    capacity = 0;
}

template <typename T>
bool MyVector<T>::empty() const {
    return size == 0;
}