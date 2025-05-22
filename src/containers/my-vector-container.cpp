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

template <typename T>
size_t MyVector<T>::get_size() const {
    return size;
}

template <typename T>
size_t MyVector<T>::get_capacity() const {
    return capacity;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
    return arr[index];
}

template <typename T>
T& MyVector<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
void MyVector<T>::insert(size_t index, const T& element) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (size == capacity) {
        resize();
    }
    for (size_t i = size; i > index; --i) {
        arr[i] = std::move(arr[i - 1]);
    }
    arr[index] = element;
    ++size;
}

template <typename T>
void MyVector<T>::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) {
        arr[i] = std::move(arr[i + 1]);
    }
    --size;
}

template <typename T>
T* MyVector<T>::begin() {
    return arr.get();
}

template <typename T>
T* MyVector<T>::end() {
    return arr.get() + size;
}

template <typename T>
T* MyVector<T>::data() {
    return arr.get();
}

template <typename T>
const T* MyVector<T>::data() const {
    return arr.get();
}

template <typename T>
void MyVector<T>::swap(MyVector& other) {
    std::swap(arr, other.arr);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

template <typename T>
void MyVector<T>::assign(size_t count, const T& value) {
    arr = std::make_unique<T[]>(count);
    size = count;
    capacity = count;
    for (size_t i = 0; i < count; ++i) {
        arr[i] = value;
    }
}

template <typename T>
void MyVector<T>::reserve(size_t new_capacity) {
    if (new_capacity > capacity) {
        std::unique_ptr<T[]> new_arr = std::make_unique<T[]>(new_capacity);
        for (size_t i = 0; i < size; ++i) {
            new_arr[i] = std::move(arr[i]);
        }
        arr = std::move(new_arr);
        capacity = new_capacity;
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit() {
    if (size < capacity) {
        std::unique_ptr<T[]> new_arr = std::make_unique<T[]>(size);
        for (size_t i = 0; i < size; ++i) {
            new_arr[i] = std::move(arr[i]);
        }
        arr = std::move(new_arr);
        capacity = size;
    }
}

