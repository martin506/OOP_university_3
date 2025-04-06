#ifndef GENERATE_STUDENTS_BY_HAND_USECASE_H
#define GENERATE_STUDENTS_BY_HAND_USECASE_H

#include "../../../common/usecase-common.h"

class GenerateStudentsByHandUseCase: UseCase<bool, void> {
    public:
        virtual void execute(bool needsParameter) = 0;
};

#endif
