#include "abstract/generate-students-by-hand-service.h"
#include <iostream>
#include <stdexcept>

GenerateStudentsByHandService::GenerateStudentsByHandService(StudentsRepositoryContract& repo)
    : studentsRepository(repo) {}

void GenerateStudentsByHandService::execute(bool needsParameter) {
    try {
        std::string name, surname;
        int examGrade;
        std::vector<int> grades;

        std::cout << "Enter student name: ";
        std::cin >> name;
        std::cout << "Enter student surname: ";
        std::cin >> surname;

        std::cout << "Enter grades (enter -1 to stop): ";
        int grade;
        while (std::cin >> grade && grade != -1) {
            if (grade < 1 || grade > 10) {
                throw std::invalid_argument("Grade must be between 1 and 10");
            }
            grades.push_back(grade);
        }

        if (grades.empty()) {
            throw std::invalid_argument("No grades entered");
        }

        examGrade = grades.back();
        grades.pop_back();

        Student student = Student(name, surname, examGrade, 0, 0);
        student.setGrades(grades);
        student.setFinalGradeWithAverage(student.calculateAverage());
        student.setFinalGradeWithMedian(student.calculateMedian());

        studentsRepository.save(student);

        std::cout << "Student data saved successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
