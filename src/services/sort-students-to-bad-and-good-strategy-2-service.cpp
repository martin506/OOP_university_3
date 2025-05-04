#include "abstract/sort-students-to-bad-and-good-strategy-2-service.h"
#include <variant>
#include <iostream>

SortStudentsToBadAndGoodServiceStrategy2::SortStudentsToBadAndGoodServiceStrategy2(StudentsRepositoryContract& badRepo, StudentsRepositoryContract& studentsRepository)
    : badStudentsRepository(badRepo), studentsRepository(studentsRepository) {}

void SortStudentsToBadAndGoodServiceStrategy2::execute(bool needsParameter) {
    StudentContainer students = studentsRepository.getStudentWithGradesVector();

    std::visit([this](auto&& container) {
        auto it = std::remove_if(container.begin(), container.end(), [this](const auto& studentWithGrades) {
            if (studentWithGrades.getFinalGradeWithAverage() < 5) {
                badStudentsRepository.save(studentWithGrades);
                return true;
            }
            return false;
        });
        container.erase(it, container.end());
    }, students);

    studentsRepository.clearData();

    std::visit([this](auto&& container) {
        for (const auto& student : container) {
            studentsRepository.save(student);
        }
    }, students);
}
