#include "student-model.h"

Student::Student()
    : name("name"), surname("surname"), examGrade(8), finalGradeWithAverage(0), finalGradeWithMedian(0) {}

Student::~Student() {
    grades.clear();
}

Student::Student(const std::string& name, const std::string& surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian)
    : name(name), surname(surname), examGrade(examGrade), finalGradeWithAverage(finalGradeWithAverage), finalGradeWithMedian(finalGradeWithMedian) {}

void Student::addGrade(int grade) {
    grades.push_back(grade);
}

void Student::removeLastGrade() {
    if (!grades.empty()) {
        grades.pop_back();
    }
}

double Student::calculateAverage() const {
    if (grades.empty()) return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0);
    return (sum / grades.size()) * 0.4 + 0.6 * examGrade;
}

double Student::calculateMedian() const {
    if (grades.empty()) return 0.0;
    std::vector<int> sortedGrades = grades;
    std::sort(sortedGrades.begin(), sortedGrades.end());
    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return ((sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0) * 0.4 + 0.6 * examGrade;
    } else {
        return sortedGrades[size / 2] * 0.4 + 0.6 * examGrade;
    }
}

bool Student::isFinalGradeWithAveragePassing() const {
    return finalGradeWithAverage >= 5;
}

bool Student::isFinalGradeWithMedianPassing() const {
    return finalGradeWithMedian >= 5;
}