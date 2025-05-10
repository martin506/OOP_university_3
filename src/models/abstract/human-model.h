#ifndef HUMAN_MODEL_H
#define HUMAN_MODEL_H

#include <string>
#include <iostream>

class Human {
private:
    std::string name;
    std::string surname;

public:
    Human();
    Human(const std::string& name, const std::string& surname);
    ~Human();

    inline std::string getName() const { return name; }
    inline void setName(const std::string& newName) { name = newName; }
    inline std::string getSurname() const { return surname; }
    inline void setSurname(const std::string& newSurname) { surname = newSurname; }

    virtual void addGrade(int grade) = 0;
    virtual void removeLastGrade() = 0;
    virtual double calculateAverage() const = 0;
    virtual double calculateMedian() const = 0;

    virtual bool isFinalGradeWithAveragePassing() const = 0;
    virtual bool isFinalGradeWithMedianPassing() const = 0;
};

#endif