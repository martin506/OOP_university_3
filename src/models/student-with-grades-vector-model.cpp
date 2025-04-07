#include "student-with-grades-vector-model.h"

StudentWithGradesVector::StudentWithGradesVector() = default;

StudentWithGradesVector::StudentWithGradesVector(const Student& student, const std::vector<int>& grades)
    : student(student), grades(grades) {}

void StudentWithGradesVector::addGrade(int grade) {
    grades.push_back(grade);
}

void StudentWithGradesVector::removeLastGrade() {
    grades.pop_back();
}

double StudentWithGradesVector::calculateAverage() const {
    if (grades.empty()) return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0);
    return ( ( sum / grades.size() ) * 0.4f + 0.6f * student.getExamGrade()) ;
}

double StudentWithGradesVector::calculateMedian() const {
    if (grades.empty()) return 0.0;
    std::vector<int> sortedGrades = grades;
    std::sort(sortedGrades.begin(), sortedGrades.end());
    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return ((sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0 * 0.4f + 0.6f * student.getExamGrade());
    } else {
        return (sortedGrades[size / 2] * 0.4f + 0.6f * student.getExamGrade());
    }
}
