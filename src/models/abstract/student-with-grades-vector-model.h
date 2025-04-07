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
    StudentWithGradesVector();
    StudentWithGradesVector(const Student& student, const std::vector<int>& grades);

    inline const Student& getStudent() const { return student; }
    inline void setStudent(const Student& newStudent) { student = newStudent; }
    inline const std::vector<int>& getGrades() const { return grades; }
    inline void setGrades(const std::vector<int>& newGrades) { grades = newGrades; }

    void addGrade(int grade);
    double calculateAverage() const;
    double calculateMedian() const;
};

#endif
