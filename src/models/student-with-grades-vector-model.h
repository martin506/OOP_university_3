#ifndef STUDENT_WITH_GRADES_VECTOR_MODEL_H
#define STUDENT_WITH_GRADES_VECTOR_MODEL_H

#include "student-model.h"
#include <vector>
#include <algorithm>
#include <numeric>

class StudentWithGradesVector {
private:
    Student student;
    std::vector<int> grades;

public:
    StudentWithGradesVector() = default;

    StudentWithGradesVector(const Student& student, const std::vector<int>& grades)
        : student(student), grades(grades) {}

    const Student& getStudent() const {
        return student;
    }

    void setStudent(const Student& newStudent) {
        student = newStudent;
    }

    const std::vector<int>& getGrades() const {
        return grades;
    }

    void setGrades(const std::vector<int>& newGrades) {
        grades = newGrades;
    }

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    double calculateAverage() const {
        if (grades.empty()) return 0.0;
        double sum = std::accumulate(grades.begin(), grades.end(), 0);
        return sum / grades.size();
    }

    double calculateMedian() const {
        if (grades.empty()) return 0.0;
        std::vector<int> sortedGrades = grades;
        std::sort(sortedGrades.begin(), sortedGrades.end());
        size_t size = sortedGrades.size();
        if (size % 2 == 0) {
            return (sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0;
        } else {
            return sortedGrades[size / 2];
        }
    }
};

#endif