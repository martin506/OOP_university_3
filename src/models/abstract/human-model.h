#ifndef HUMAN_MODEL_H
#define HUMAN_MODEL_H

#include <string>

class Human {
private:
    std::string name;
    std::string surname;

public:
    Human();
    Human(const std::string& name, const std::string& surname);
    ~Human();
    Human(const Human& other);                // Copy Constructor
    Human& operator=(const Human& other);     // Copy Assignment Operator
    Human(Human&& other) noexcept;            // Move Constructor
    Human& operator=(Human&& other) noexcept; // Move Assignment Operator

    inline std::string getName() const { return name; }
    inline void setName(const std::string& newName) { name = newName; }
    inline std::string getSurname() const { return surname; }
    inline void setSurname(const std::string& newSurname) { surname = newSurname; }
};

#endif