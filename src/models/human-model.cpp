#include "abstract/human-model.h"

Human::Human() : name("Unknown"), surname("Unknown") {}

Human::Human(const std::string& name, const std::string& surname) : name(name), surname(surname) {}

Human::~Human() = default;

// Copy Constructor
Human::Human(const Human& other) : name(other.name), surname(other.surname) {}

// Copy Assignment Operator
Human& Human::operator=(const Human& other) {
    if (this == &other) return *this; // Handle self-assignment
    name = other.name;
    surname = other.surname;
    return *this;
}

// Move Constructor
Human::Human(Human&& other) noexcept : name(std::move(other.name)), surname(std::move(other.surname)) {}

// Move Assignment Operator
Human& Human::operator=(Human&& other) noexcept {
    if (this == &other) return *this; // Handle self-assignment
    name = std::move(other.name);
    surname = std::move(other.surname);
    return *this;
}
