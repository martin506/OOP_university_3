#ifndef SORT_STUDENTS_SERVICE_H
#define SORT_STUDENTS_SERVICE_H

#include "../usecases/sort-students-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"

class SortStudentsService : public SortStudentsUseCase {
private:
    StudentsRepositoryContract& studentsRepository;

public:
    SortStudentsService(StudentsRepositoryContract& studentsRepository);
    void execute(bool needsParameter) override;
};

#endif 
