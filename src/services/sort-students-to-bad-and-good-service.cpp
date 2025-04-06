#include "abstract/sort-students-to-bad-and-good-service.h"
#include <variant>

SortStudentsToBadAndGoodService::SortStudentsToBadAndGoodService(StudentsRepositoryContract* goodRepository, StudentsRepositoryContract* badRepo, StudentsRepositoryContract* studentsRepository)
    : goodStudentsRepository(goodRepository), badStudentsRepository(badRepo), studentsRepository(studentsRepository) {}

void SortStudentsToBadAndGoodService::execute(bool needsParameter) {
    StudentContainer students = studentsRepository->getStudentWithGradesVector();

    std::visit([this](auto&& container) {
        for (const auto& student : container) {
            if (student.student.isFinalGradeWithAveragePassing()) {
                goodStudentsRepository->save(student);
            } else {
                badStudentsRepository->save(student);
            }
        }
    }, students);
}

