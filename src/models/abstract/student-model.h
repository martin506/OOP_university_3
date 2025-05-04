#ifndef STUDENT_MODEL_H
#define STUDENT_MODEL_H

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Student {
private:
    std::string name;
    std::string surname;
    int examGrade;
    double finalGradeWithAverage;
    double finalGradeWithMedian;
    std::vector<int> grades;

public:
    Student();
    ~Student();
    Student(const std::string& name, const std::string& surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian);

    inline std::string getName() const { return name; }
    inline void setName(const std::string& newName) { name = newName; }
    inline std::string getSurname() const { return surname; }
    inline void setSurname(const std::string& newSurname) { surname = newSurname; }
    inline int getExamGrade() const { return examGrade; }
    inline void setExamGrade(int newExamGrade) { examGrade = newExamGrade; }
    inline double getFinalGradeWithAverage() const { return finalGradeWithAverage; }
    inline void setFinalGradeWithAverage(double newFinalGradeWithAverage) { finalGradeWithAverage = newFinalGradeWithAverage; }
    inline double getFinalGradeWithMedian() const { return finalGradeWithMedian; }
    inline void setFinalGradeWithMedian(double newFinalGradeWithMedian) { finalGradeWithMedian = newFinalGradeWithMedian; }

    inline const std::vector<int>& getGrades() const { return grades; }
    inline void setGrades(const std::vector<int>& newGrades) { grades = newGrades; }

    void addGrade(int grade);
    void removeLastGrade();
    double calculateAverage() const;
    double calculateMedian() const;

    bool isFinalGradeWithAveragePassing() const;
    bool isFinalGradeWithMedianPassing() const;
};

#endif
