#include "abstract/student-model.h"

Student::Student()
    : Human(), examGrade(8), finalGradeWithAverage(0), finalGradeWithMedian(0) {}

Student::~Student() = default;

Student::Student(const std::string& name, const std::string& surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian)
    : Human(name, surname), examGrade(examGrade), finalGradeWithAverage(finalGradeWithAverage), finalGradeWithMedian(finalGradeWithMedian) {}

// Copy Constructor
Student::Student(const Student& other)
    : Human(other), examGrade(other.examGrade), finalGradeWithAverage(other.finalGradeWithAverage),
      finalGradeWithMedian(other.finalGradeWithMedian), grades(other.grades) {}

// Copy Assignment Operator
Student& Student::operator=(const Student& other) {
    if (this == &other) return *this; // Handle self-assignment
    Human::operator=(other);
    examGrade = other.examGrade;
    finalGradeWithAverage = other.finalGradeWithAverage;
    finalGradeWithMedian = other.finalGradeWithMedian;
    grades = other.grades;
    return *this;
}

// Move Constructor
Student::Student(Student&& other) noexcept
    : Human(std::move(other)), examGrade(other.examGrade), finalGradeWithAverage(other.finalGradeWithAverage),
      finalGradeWithMedian(other.finalGradeWithMedian), grades(std::move(other.grades)) {
    other.examGrade = 0;
    other.finalGradeWithAverage = 0;
    other.finalGradeWithMedian = 0;
}

// Move Assignment Operator
Student& Student::operator=(Student&& other) noexcept {
    if (this == &other) return *this; // Handle self-assignment
    Human::operator=(std::move(other));
    examGrade = other.examGrade;
    finalGradeWithAverage = other.finalGradeWithAverage;
    finalGradeWithMedian = other.finalGradeWithMedian;
    grades = std::move(other.grades);

    other.examGrade = 0;
    other.finalGradeWithAverage = 0;
    other.finalGradeWithMedian = 0;
    return *this;
}

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