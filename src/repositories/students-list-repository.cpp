#include "students-list-repository.h"

StudentsListRepository::StudentsListRepository(InputManagerRepositoryContract& inputManagerRepository)
    : inputManagerRepository(inputManagerRepository) {}

void StudentsListRepository::save(StudentWithGradesVector studentWithGradesVector) {
    students.push_back(std::move(studentWithGradesVector));
}

StudentContainer StudentsListRepository::getStudentWithGradesVector() {
    return students;
}

void StudentsListRepository::sortData() {
    InputManager inputManager = inputManagerRepository.getInputManager();
    switch (inputManager.getSortingChoice()) {
        case InputManager::SURNAME:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.getStudent().getSurname() < b.getStudent().getSurname();
            });
            break;
        case InputManager::NAME:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.getStudent().getName() < b.getStudent().getName();
            });
            break;
        case InputManager::FINAL_GRADE_WITH_AVERAGE:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.getStudent().getFinalGradeWithAverage() < b.getStudent().getFinalGradeWithAverage();
            });
            break;
        case InputManager::FINAL_GRADE_WITH_MEDIAN:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.getStudent().getFinalGradeWithMedian() < b.getStudent().getFinalGradeWithMedian();
            });
            break;
        default:
            throw std::invalid_argument("Invalid sorting choice");
    }
}

void StudentsListRepository::clearData() {
    students.clear();
}
