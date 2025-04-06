#ifndef PRINT_STUDENTS_TO_CONSOLE_H
#define PRINT_STUDENTS_TO_CONSOLE_H

#include "../../../common/usecase-common.h"

class PrintStudentsToConsoleUseCase: UseCase<bool, void> {
    public: 
        virtual void execute(bool needsParameter) = 0; 
};

#endif