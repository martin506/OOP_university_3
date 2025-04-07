#include "student-model.h"

Student::Student()
    : name("name"), surname("surname"), examGrade(10), finalGradeWithAverage(0), finalGradeWithMedian(0) {}

Student::Student(const std::string& name, const std::string& surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian)
    : name(name), surname(surname), examGrade(examGrade), finalGradeWithAverage(finalGradeWithAverage), finalGradeWithMedian(finalGradeWithMedian) {}

bool Student::isFinalGradeWithAveragePassing() const {
    return finalGradeWithAverage >= 5;
}

bool Student::isFinalGradeWithMedianPassing() const {
    return finalGradeWithMedian >= 5;
}
