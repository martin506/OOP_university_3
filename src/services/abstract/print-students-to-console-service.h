#ifndef PRINT_STUDENTS_TO_CONSOLE_SERVICE_H
#define PRINT_STUDENTS_TO_CONSOLE_SERVICE_H

#include "../usecases/print-students-to-console-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"
#include <iostream>
#include <iomanip>

class PrintStudentsToConsoleService : public PrintStudentsToConsoleUseCase {
private:
    StudentsRepositoryContract& studentsRepository;

public:
    PrintStudentsToConsoleService(StudentsRepositoryContract& studentsRepository);
    void execute(bool needsParameter) override;
};

#endif 