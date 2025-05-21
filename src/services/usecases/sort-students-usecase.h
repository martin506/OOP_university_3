#ifndef SORT_STUDENTS_USECASE_H
#define SORT_STUDENTS_USECASE_H

#include "../../../common/usecase-common.h"

class SortStudentsUseCase : UseCase<bool, void>{
public:
    virtual void execute(bool needsParameter) = 0;
};

#endif