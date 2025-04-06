#ifndef STUDENT_MODEL_H
#define STUDENT_MODEL_H

#include <string>

struct Student
{
    std::string name = "name";
    std::string surname = "surname";
    int examGrade = 10;

    double finalGradeWithAverage = 0;
    double finalGradeWithMedian = 0;

    bool isFinalGradeWithAveragePassing() const
    {
        return finalGradeWithAverage >= 5;
    }

    bool isFinalGradeWithMedianPassing() const
    {
        return finalGradeWithMedian >= 5;
    }

    Student() : name("name"), surname("surname"), examGrade(10), finalGradeWithAverage(0), finalGradeWithMedian(0) {}

    Student(
        const std::string &name,
        const std::string &surname,
        int examGrade,
        double finalGradeWithAverage,
        double finalGradeWithMedian
    ) : name(name), surname(surname), examGrade(examGrade), finalGradeWithAverage(finalGradeWithAverage), finalGradeWithMedian(finalGradeWithMedian) {}
};

#endif
