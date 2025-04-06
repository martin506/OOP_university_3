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
    switch (inputManager.sortingChoice) {
        case InputManager::SURNAME:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.student.surname < b.student.surname;
            });
            break;
        case InputManager::NAME:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.student.name < b.student.name;
            });
            break;
        case InputManager::FINAL_GRADE_WITH_AVERAGE:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.student.finalGradeWithAverage < b.student.finalGradeWithAverage;
            });
            break;
        case InputManager::FINAL_GRADE_WITH_MEDIAN:
            students.sort([](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
                return a.student.finalGradeWithMedian < b.student.finalGradeWithMedian;
            });
            break;
        default:
            throw std::invalid_argument("Invalid sorting choice");
    }
}

void StudentsListRepository::clearData() {
    students.clear();
}
