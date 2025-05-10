#ifndef HUMAN_MODEL_H
#define HUMAN_MODEL_H

#include <string>

class Human {
private:
    std::string name;
    std::string surname;

public:
    inline std::string getName() const { return name; }
    inline void setName(const std::string &newName) { name = newName; }
    inline std::string getSurname() const { return surname; }
    inline void setSurname(const std::string &newSurname) { surname = newSurname; }

};

#endif