#ifndef GENERATE_STUDENTS_TO_FILE_USECASE_H
#define GENERATE_STUDENTS_TO_FILE_USECASE_H

#include "../../../common/usecase-common.h"
#include <string>

class GenerateStudentsToFileUseCase: UseCase<std::string, void> {
    public: 
        virtual void execute(std::string fileSize) = 0;
};

#endif