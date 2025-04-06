#ifndef CREATE_STUDENTS_AUTOMATICALLY_SERVICE_H
#define CREATE_STUDENTS_AUTOMATICALLY_SERVICE_H

#include "../usecases/create-students-automatically-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"
#include <vector>
#include <string>
#include <utility>

class CreateStudentsAutomaticallyService : public CreateStudentsAutomaticallyUseCase {
private:
    StudentsRepositoryContract* studentsRepository;

    std::vector<std::string> names = {
        "John", "Jane", "Alice", "Bob", "Charlie", "Diana", "Edward", "Fiona", "George", "Hannah",
        "Ian", "Julia", "Kevin", "Laura", "Michael", "Nina", "Oscar", "Paula", "Quentin", "Rachel", "Mac", "Malcolm"
    };

    std::vector<std::string> surnames = {
        "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
        "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin"
    };

    std::pair<std::string, std::string> getRandomNameAndSurname();
    int getRandomGrade();

public:
    CreateStudentsAutomaticallyService(StudentsRepositoryContract* studentsRepository);
    void execute(int numberOfStudents) override;
};

#endif 
