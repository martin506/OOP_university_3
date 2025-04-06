#ifndef PRINT_STUDENTS_TO_FILE_SERVICE_H
#define PRINT_STUDENTS_TO_FILE_SERVICE_H

#include "../usecases/print-students-to-file-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

class PrintStudentsToFileService : public PrintStudentsToFileUseCase {
private:
    StudentsRepositoryContract* studentsRepository;

public:
    PrintStudentsToFileService(StudentsRepositoryContract* repo);
    void execute(std::string fileName) override;
};

#endif
