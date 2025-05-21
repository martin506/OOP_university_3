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
};

#endif // PERSONAL_VECTOR_H