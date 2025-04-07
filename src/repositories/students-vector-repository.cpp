#include "abstract/students-vector-repository.h"

StudentsVectorRepository::StudentsVectorRepository(InputManagerRepositoryContract &inputManagerRepository)
    : inputManagerRepository(inputManagerRepository) {}

void StudentsVectorRepository::save(StudentWithGradesVector studentWithGradesVector)
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
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.getStudent().getSurname() < b.getStudent().getSurname(); });
        break;
    case InputManager::NAME:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.getStudent().getName() < b.getStudent().getName(); });
        break;
    case InputManager::FINAL_GRADE_WITH_AVERAGE:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.getStudent().getFinalGradeWithAverage() < b.getStudent().getFinalGradeWithAverage(); });
        break;
    case InputManager::FINAL_GRADE_WITH_MEDIAN:
        std::sort(students.begin(), students.end(), [](const StudentWithGradesVector &a, const StudentWithGradesVector &b)
                  { return a.getStudent().getFinalGradeWithMedian() < b.getStudent().getFinalGradeWithMedian(); });
        break;
    default:
        throw std::invalid_argument("Invalid sorting choice");
    }
}

void StudentsVectorRepository::clearData()
{
    students.clear();
}
