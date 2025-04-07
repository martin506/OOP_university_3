#include "abstract/print-students-to-console-service.h"
#include <iostream>
#include <iomanip>
#include <variant>

PrintStudentsToConsoleService::PrintStudentsToConsoleService(StudentsRepositoryContract& studentsRepository)
    : studentsRepository(studentsRepository) {}

void PrintStudentsToConsoleService::execute(bool needsParameter) {
    try {
        std::cout << std::left << std::setw(20) << "Name"
                  << std::left << std::setw(20) << "Surname"
                  << std::left << std::setw(10) << "Exam"
                  << std::left << std::setw(15) << "Avg Grade"
                  << std::left << std::setw(15) << "Med Grade" << "\n";

        StudentContainer students = studentsRepository.getStudentWithGradesVector();

        std::visit([](auto&& container) {
            for (const auto& studentWithGrades : container) {
                std::cout << std::left << std::setw(20) << studentWithGrades.getStudent().getName()
                          << std::left << std::setw(20) << studentWithGrades.getStudent().getSurname()
                          << std::left << std::setw(10) << studentWithGrades.getStudent().getExamGrade()
                          << std::left << std::setw(15) << studentWithGrades.getStudent().getFinalGradeWithAverage()
                          << std::left << std::setw(15) << studentWithGrades.getStudent().getFinalGradeWithMedian() << "\n";
            }
        }, students);

        std::cout << "Student data printed to console successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
