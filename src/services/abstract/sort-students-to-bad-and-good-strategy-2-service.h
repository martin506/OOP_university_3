#ifndef SORT_STUDENTS_TO_BAD_AND_GOOD_SERVICE_STRATEGY_2_H
#define SORT_STUDENTS_TO_BAD_AND_GOOD_SERVICE_STRATEGY_2_H

#include "../usecases/sort-students-to-bad-and-good-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"

class SortStudentsToBadAndGoodServiceStrategy2 : public SortStudentsToBadAndGoodUseCase
{
private:
    StudentsRepositoryContract &badStudentsRepository;
    StudentsRepositoryContract &studentsRepository;

public:
    SortStudentsToBadAndGoodServiceStrategy2(StudentsRepositoryContract &badRepo, StudentsRepositoryContract &studentsRepository);
    void execute(bool needsParameter) override;
};

#endif
