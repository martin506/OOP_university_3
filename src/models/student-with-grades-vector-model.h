#ifndef STUDENT_WITH_GRADES_VECTOR_MODEL_H
#define STUDENT_WITH_GRADES_VECTOR_MODEL_H

#include "student-model.h"
#include <vector>
#include <algorithm>
#include <numeric>

struct StudentWithGradesVector {
    Student student;
    std::vector<int> grades;

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

    StudentWithGradesVector() = default;
};

#endif 