#include "students-deque-repository.h"

StudentsDequeRepository::StudentsDequeRepository(InputManagerRepositoryContract &inputManagerRepository)
    : inputManagerRepository(inputManagerRepository) {}

void StudentsDequeRepository::save(StudentWithGradesVector studentWithGradesVector)
{
    students.push_back(std::move(studentWithGradesVector));
}

StudentContainer StudentsDequeRepository::getStudentWithGradesVector()
{
    return students;
}

void StudentsDequeRepository::sortData()
{
    InputManager inputManager = inputManagerRepository.getInputManager();
    switch (inputManager.sortingChoice)
    {
    case InputManager::SURNAME:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.student.surname < b.student.surname; });
        break;
    case InputManager::NAME:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.student.name < b.student.name; });
        break;
    case InputManager::FINAL_GRADE_WITH_AVERAGE:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.student.finalGradeWithAverage < b.student.finalGradeWithAverage; });
        break;
    case InputManager::FINAL_GRADE_WITH_MEDIAN:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.student.finalGradeWithMedian < b.student.finalGradeWithMedian; });
        break;
    default:
        throw std::invalid_argument("Invalid sorting choice");
    }
}

void StudentsDequeRepository::clearData()
{
    students.clear();
}