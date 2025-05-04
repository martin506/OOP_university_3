#ifndef SORT_STUDENTS_TO_BAD_AND_GOOD_CONTRACT_H
#define SORT_STUDENTS_TO_BAD_AND_GOOD_CONTRACT_H

#include "../../../common/usecase-common.h"
#include "../../models/abstract/student-model.h"

class SortStudentsToBadAndGoodUseCase : UseCase<bool, void> {
public:
    virtual void execute(bool needsParameter) = 0;
};

#endif
