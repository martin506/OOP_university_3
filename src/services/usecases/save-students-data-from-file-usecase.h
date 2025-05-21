#ifndef SAVE_STUDENTS_DATA_FROM_FILE_USECASE_H
#define SAVE_STUDENTS_DATA_FROM_FILE_USECASE_H

#include "../../../common/usecase-common.h"
#include <string>

class SaveStudentsDataFromFileUseCase: UseCase<std::string, void> {
    public:
        virtual void execute(std::string fileName) = 0;
};

#endif