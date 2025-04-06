#ifndef SAVE_STUDENTS_DATA_FROM_FILE_SERVICE_H
#define SAVE_STUDENTS_DATA_FROM_FILE_SERVICE_H

#include "../usecases/save-students-data-from-file-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

class SaveStudentsDataFromFileService : public SaveStudentsDataFromFileUseCase {
private:
    StudentsRepositoryContract* studentsRepository;

public:
    SaveStudentsDataFromFileService(StudentsRepositoryContract* repo);
    void execute(std::string filename) override;
};

#endif 
