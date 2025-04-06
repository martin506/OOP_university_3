#ifndef SORT_STUDENTS_TO_BAD_AND_GOOD_SERVICE_H
#define SORT_STUDENTS_TO_BAD_AND_GOOD_SERVICE_H

#include "../usecases/sort-students-to-bad-and-good-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"

class SortStudentsToBadAndGoodService : public SortStudentsToBadAndGoodUseCase {
private:
    StudentsRepositoryContract* goodStudentsRepository;
    StudentsRepositoryContract* badStudentsRepository;
    StudentsRepositoryContract* studentsRepository;

public:
    SortStudentsToBadAndGoodService(StudentsRepositoryContract* goodRepository, StudentsRepositoryContract* badRepo, StudentsRepositoryContract* studentsRepository);
    void execute(bool needsParameter) override;
};

#endif 
