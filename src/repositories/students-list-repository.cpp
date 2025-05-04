#include "students-list-repository.h"

StudentsListRepository::StudentsListRepository(InputManagerRepositoryContract& inputManagerRepository)
    : inputManagerRepository(inputManagerRepository) {}

void StudentsListRepository::save(Student studentWithGradesVector) {
    students.push_back(std::move(studentWithGradesVector));
}

StudentContainer StudentsListRepository::getStudentWithGradesVector() {
    return students;
}

void StudentsListRepository::sortData() {
    InputManager inputManager = inputManagerRepository.getInputManager();
    switch (inputManager.getSortingChoice()) {
        case InputManager::SURNAME:
            students.sort([](const Student& a, const Student& b) {
                return a.getSurname() < b.getSurname();
            });
            break;
        case InputManager::NAME:
            students.sort([](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
            break;
        case InputManager::FINAL_GRADE_WITH_AVERAGE:
            students.sort([](const Student& a, const Student& b) {
                return a.getFinalGradeWithAverage() < b.getFinalGradeWithAverage();
            });
            break;
        case InputManager::FINAL_GRADE_WITH_MEDIAN:
            students.sort([](const Student& a, const Student& b) {
                return a.getFinalGradeWithMedian() < b.getFinalGradeWithMedian();
            });
            break;
        default:
            throw std::invalid_argument("Invalid sorting choice");
    }
}

void StudentsListRepository::clearData() {
    students.clear();
}
