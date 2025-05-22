#ifndef PERSONAL_VECTOR_H
#define PERSONAL_VECTOR_H

#include <memory>
#include <stdexcept> // For std::out_of_range
#include <algorithm> // For std::sort, std::reverse

template <typename T>
class MyVector {
private:
    std::unique_ptr<T[]> arr;
    size_t size;
    size_t capacity;

    void resize(); // Function to handle resizing

public:
    MyVector();                 // Default constructor
    ~MyVector() = default;      // Destructor (default since unique_ptr handles cleanup)

    MyVector(const MyVector& other);        // Copy constructor
    MyVector& operator=(const MyVector& other); // Copy assignment operator

    MyVector(MyVector&& other) noexcept;        // Move constructor
    MyVector& operator=(MyVector&& other) noexcept; // Move assignment operator

    void push_back(const T& element); // Add element
    void pop_back(); // Remove last element

    void clear(); // Clear all elements
    bool empty() const; // Check if the vector is empty

    size_t get_size() const;
    size_t get_capacity() const;

    T& operator[](size_t index);

    T& at(size_t index); // Bounds-checked access

    void insert(size_t index, const T& element); // Insert element at a specific index
    void erase(size_t index); // Remove element at a specific index

    void erase(T* first, T* last); // Remove elements in a range

    T* begin(); // Iterator to the beginning
    T* end();   // Iterator to the end

    T* data(); // Get raw pointer to the underlying array
    const T* data() const; // Get const raw pointer to the underlying array

    void swap(MyVector& other); // Swap contents with another vector
    void assign(size_t count, const T& value); // Assign multiple values

    void reserve(size_t new_capacity); // Reserve space without changing size
    void shrink_to_fit(); // Reduce capacity to fit size

    void sort(); // Sort elements in ascending order
    void reverse(); // Reverse the order of elements
    void remove_if(bool (*predicate)(const T&)); // Remove elements based on a predicate
    void swap_elements(size_t index1, size_t index2); // Swap two elements
    void fill(const T& value); // Fill the vector with a specific value
};

// Implementation of MyVector

template <typename T>
MyVector<T>::MyVector() : arr(nullptr), size(0), capacity(0) {}

// copy constructor
template <typename T>
MyVector<T>::MyVector(const MyVector& other)
    : size(other.size), capacity(other.capacity), arr(std::make_unique<T[]>(other.capacity)) {
    for (size_t i = 0; i < other.size; ++i) {
        arr[i] = other.arr[i];
    }
}

// copy assignment operator
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    size = other.size;
    capacity = other.capacity;
    arr = std::make_unique<T[]>(other.capacity);

    for (size_t i = 0; i < other.size; ++i) {
        arr[i] = other.arr[i];
    }

    return *this;
}

// move assignment operator
template <typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept
    : size(other.size), capacity(other.capacity), arr(std::move(other.arr)) {
    other.size = 0;
    other.capacity = 0;
}

// move assignment operator
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    size = other.size;
    capacity = other.capacity;
    arr = std::move(other.arr);

    other.size = 0;
    other.capacity = 0;

    return *this;
}

// Function to resize the vector when needed
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
void MyVector<T>::erase(T* first, T* last) {
    if (first < begin() || last > end() || first > last) {
        throw std::out_of_range("Invalid range for erase");
    }

    size_t start_index = first - begin();
    size_t end_index = last - begin();

    for (size_t i = end_index; i < size; ++i) {
        arr[start_index++] = std::move(arr[i]);
    }

    size -= (last - first);
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

template <typename T>
void MyVector<T>::sort() {
    std::sort(begin(), end());
}

template <typename T>
void MyVector<T>::reverse() {
    std::reverse(begin(), end());
}

template <typename T>
void MyVector<T>::remove_if(bool (*predicate)(const T&)) {
    size_t new_size = 0;
    for (size_t i = 0; i < size; ++i) {
        if (!predicate(arr[i])) {
            arr[new_size++] = std::move(arr[i]);
        }
    }
    size = new_size;
}

template <typename T>
void MyVector<T>::swap_elements(size_t index1, size_t index2) {
    if (index1 >= size || index2 >= size) {
        throw std::out_of_range("Index out of range");
    }
    std::swap(arr[index1], arr[index2]);
}

template <typename T>
void MyVector<T>::fill(const T& value) {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

#endif // PERSONAL_VECTOR_H