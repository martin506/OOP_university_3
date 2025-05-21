#ifndef PERSONAL_VECTOR_H
#define PERSONAL_VECTOR_H

template <typename T>
class PersonalVector {
private:
    T* arr;        
    size_t size;   
    size_t capacity; 

    void resize(); // Utility function to handle resizing

public:
    PersonalVector();                 // Default constructor
    ~PersonalVector();                // Destructor

    PersonalVector(const PersonalVector& other);        // Copy constructor
    PersonalVector& operator=(const PersonalVector& other); // Copy assignment operator

    PersonalVector(PersonalVector&& other) noexcept;        // Move constructor
    PersonalVector& operator=(PersonalVector&& other) noexcept; // Move assignment operator

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

    T* begin(); // Iterator to the beginning
    T* end();   // Iterator to the end

    T* data(); // Get raw pointer to the underlying array
    const T* data() const; // Get const raw pointer to the underlying array

    void swap(PersonalVector& other); // Swap contents with another vector
    void assign(size_t count, const T& value); // Assign multiple values

    void reserve(size_t new_capacity); // Reserve space without changing size
    void shrink_to_fit(); // Reduce capacity to fit size

    void sort(); // Sort elements in ascending order
    void reverse(); // Reverse the order of elements
    void remove_if(bool (*predicate)(const T&)); // Remove elements based on a predicate
    void swap_elements(size_t index1, size_t index2); // Swap two elements
    void fill(const T& value); // Fill the vector with a specific value
};

#endif // PERSONAL_VECTOR_H