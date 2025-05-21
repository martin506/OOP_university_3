#include "students-deque-repository.h"

StudentsDequeRepository::StudentsDequeRepository(InputManagerRepositoryContract &inputManagerRepository)
    : inputManagerRepository(inputManagerRepository) {}

void StudentsDequeRepository::save(Student studentWithGradesVector)
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
    switch (inputManager.getSortingChoice())
    {
    case InputManager::SURNAME:
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                  { return a.getSurname() < b.getSurname(); });
        break;
    case InputManager::NAME:
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                  { return a.getName() < b.getName(); });
        break;
    case InputManager::FINAL_GRADE_WITH_AVERAGE:
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                  { return a.getFinalGradeWithAverage() < b.getFinalGradeWithAverage(); });
        break;
    case InputManager::FINAL_GRADE_WITH_MEDIAN:
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                  { return a.getFinalGradeWithMedian() < b.getFinalGradeWithMedian(); });
        break;
    default:
        throw std::invalid_argument("Invalid sorting choice");
    }
}

void StudentsDequeRepository::clearData()
{
    students.clear();
}
