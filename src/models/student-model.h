#ifndef STUDENT_MODEL_H
#define STUDENT_MODEL_H

#include <string>

class Student {
private:
    std::string name;
    std::string surname;
    int examGrade;
    double finalGradeWithAverage;
    double finalGradeWithMedian;

public:
    Student()
        : name("name"), surname("surname"), examGrade(10), finalGradeWithAverage(0), finalGradeWithMedian(0) {}

    Student(const std::string& name, const std::string& surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian)
        : name(name), surname(surname), examGrade(examGrade), finalGradeWithAverage(finalGradeWithAverage), finalGradeWithMedian(finalGradeWithMedian) {}

    inline std::string getName() const { return name; }
    inline void setName(const std::string& newName) { name = newName; }
    inline std::string getSurname() const { return surname; }
    inline void setSurname(const std::string& newSurname) { surname = newSurname; }
    inline int getExamGrade() const { return examGrade; }
    inline void setExamGrade(int newExamGrade) { examGrade = newExamGrade; }
    inline double getFinalGradeWithAverage() const { return finalGradeWithAverage; }
    inline void setFinalGradeWithAverage(double newFinalGradeWithAverage) { finalGradeWithAverage = newFinalGradeWithAverage; }
    inline double getFinalGradeWithMedian() const { return finalGradeWithMedian; }
    inline void setFinalGradeWithMedian(double newFinalGradeWithMedian) { finalGradeWithMedian = newFinalGradeWithMedian; }

    bool isFinalGradeWithAveragePassing() const {
        return finalGradeWithAverage >= 5;
    }

    bool isFinalGradeWithMedianPassing() const {
        return finalGradeWithMedian >= 5;
    }
};

#endif
