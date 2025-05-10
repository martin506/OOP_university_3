#ifndef STUDENT_MODEL_H
#define STUDENT_MODEL_H

#include "human-model.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <ostream>
#include <iostream>
#include <fstream>

class Student : public Human {
private:
    int examGrade;
    double finalGradeWithAverage;
    double finalGradeWithMedian;
    std::vector<int> grades;

public:
    Student();
    ~Student();
    Student(const std::string& name, const std::string& surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian);

    Student(const Student& other);                // Copy Constructor
    Student& operator=(const Student& other);     // Copy Assignment Operator
    Student(Student&& other) noexcept;            // Move Constructor
    Student& operator=(Student&& other) noexcept; // Move Assignment Operator

    friend std::ostream& operator<<(std::ostream& out, const Student& stud);
    friend std::istream& operator>>(std::istream& in, Student& stud);

    inline int getExamGrade() const { return examGrade; }
    inline void setExamGrade(int newExamGrade) { examGrade = newExamGrade; }
    inline double getFinalGradeWithAverage() const { return finalGradeWithAverage; }
    inline void setFinalGradeWithAverage(double newFinalGradeWithAverage) { finalGradeWithAverage = newFinalGradeWithAverage; }
    inline double getFinalGradeWithMedian() const { return finalGradeWithMedian; }
    inline void setFinalGradeWithMedian(double newFinalGradeWithMedian) { finalGradeWithMedian = newFinalGradeWithMedian; }

    inline const std::vector<int>& getGrades() const { return grades; }
    inline void setGrades(const std::vector<int>& newGrades) { grades = newGrades; }

    void addGrade(int grade) override;
    void removeLastGrade() override;
    double calculateAverage() const override;
    double calculateMedian() const override;

    bool isFinalGradeWithAveragePassing() const override;
    bool isFinalGradeWithMedianPassing() const override;
};

#endif
