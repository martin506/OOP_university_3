#ifndef CREATE_STUDENTS_AUTOMATICALLY_USECASE_H
#define CREATE_STUDENTS_AUTOMATICALLY_USECASE_H

#include "../../../common/usecase-common.h"

class CreateStudentsAutomaticallyUseCase: UseCase<int, void> {
    public:
        virtual void execute(int numberOfStudents) = 0;
};

#endif