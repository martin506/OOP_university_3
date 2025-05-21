#include "abstract/students-vector-repository.h"

StudentsVectorRepository::StudentsVectorRepository(InputManagerRepositoryContract &inputManagerRepository)
    : inputManagerRepository(inputManagerRepository) {}

void StudentsVectorRepository::save(Student studentWithGradesVector)
{
    students.push_back(std::move(studentWithGradesVector));
}

StudentContainer StudentsVectorRepository::getStudentWithGradesVector()
{
    return students;
}

void StudentsVectorRepository::sortData()
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

void StudentsVectorRepository::clearData()
{
    students.clear();
}
