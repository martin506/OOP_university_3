#ifndef PRINT_STUDENTS_TO_FILE_H
#define PRINT_STUDENTS_TO_FILE_H

#include "../../../common/usecase-common.h"
#include <string>

class PrintStudentsToFileUseCase: UseCase<std::string, void> {
    public:
        virtual void execute(std::string fileName) = 0;
};

#endif