#include "abstract/students-vector-repository.h"

StudentsVectorRepository::StudentsVectorRepository(InputManagerRepositoryContract* inputManagerRepositoryRepository)
    : inputManagerRepositoryRepository(inputManagerRepositoryRepository) {}

StudentsVectorRepository::~StudentsVectorRepository() {
    students.clear();
}

void StudentsVectorRepository::save(StudentWithGradesVector studentWithGradesVector)
{
    students.push_back(studentWithGradesVector);
}

StudentContainer StudentsVectorRepository::getStudentWithGradesVector()
{
    return students;
}

void StudentsVectorRepository::sortData()
{
    InputManager inputManager = inputManagerRepositoryRepository->getInputManager();
    switch (inputManager.sortingChoice)
    {
    case InputManager::SURNAME:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
            return a.student.surname < b.student.surname;
        });
        break;
    case InputManager::NAME:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
            return a.student.name < b.student.name;
        });
        break;
    case InputManager::FINAL_GRADE_WITH_AVERAGE:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
            return a.student.finalGradeWithAverage < b.student.finalGradeWithAverage;
        });
        break;
    case InputManager::FINAL_GRADE_WITH_MEDIAN:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
            return a.student.finalGradeWithMedian < b.student.finalGradeWithMedian;
        });
        break;
    default:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector& a, const StudentWithGradesVector& b) {
            return a.student.name < b.student.name;
        });
        break;
    }
}

void StudentsVectorRepository::clearData()
{
    students.clear();
}
