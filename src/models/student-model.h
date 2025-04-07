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

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    std::string getSurname() const {
        return surname;
    }

    void setSurname(const std::string& newSurname) {
        surname = newSurname;
    }

    int getExamGrade() const {
        return examGrade;
    }

    void setExamGrade(int newExamGrade) {
        examGrade = newExamGrade;
    }

    double getFinalGradeWithAverage() const {
        return finalGradeWithAverage;
    }

    void setFinalGradeWithAverage(double newFinalGradeWithAverage) {
        finalGradeWithAverage = newFinalGradeWithAverage;
    }

    double getFinalGradeWithMedian() const {
        return finalGradeWithMedian;
    }

    void setFinalGradeWithMedian(double newFinalGradeWithMedian) {
        finalGradeWithMedian = newFinalGradeWithMedian;
    }

    bool isFinalGradeWithAveragePassing() const {
        return finalGradeWithAverage >= 5;
    }

    bool isFinalGradeWithMedianPassing() const {
        return finalGradeWithMedian >= 5;
    }
};

#endif
