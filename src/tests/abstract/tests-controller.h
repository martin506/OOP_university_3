#ifndef TESTS_CONTROLLER_H
#define TESTS_CONTROLLER_H

#include "module-test.h"
#include "generate-file-duration-test.h"
#include "input-duration-test.h"
#include "../../repositories/contracts/students-repository-contract.h"
#include "../../services/usecases/generate-students-to-file-usecase.h"
#include "../../services/usecases/save-students-data-from-file-usecase.h"
#include "../../services/usecases/sort-students-usecase.h"
#include "../../services/usecases/sort-students-to-bad-and-good-usecase.h"
#include "../../services/usecases/print-students-to-file-usecase.h"

class TestsController {
private:
    GenerateFileDurationTest generateFileDurationTest;
    ModuleTest moduleTest;
    InputDurationTest inputDurationTest;
    StudentsRepositoryContract* studentsRepo;
    GenerateStudentsToFileUseCase* generateService;
    SaveStudentsDataFromFileUseCase* saveService;
    SortStudentsUseCase* sortService;
    SortStudentsToBadAndGoodUseCase* sortToBadAndGoodService;
    PrintStudentsToFileUseCase* printGoodStudentsService;
    PrintStudentsToFileUseCase* printBadStudentsService;

public:
    TestsController(
        StudentsRepositoryContract* studentsRepo,
        GenerateStudentsToFileUseCase* generateService,
        SaveStudentsDataFromFileUseCase* saveService,
        SortStudentsUseCase* sortService,
        SortStudentsToBadAndGoodUseCase* sortToBadAndGoodService,
        PrintStudentsToFileUseCase* printGoodStudentsService,
        PrintStudentsToFileUseCase* printBadStudentsService
    );

    void runModuleTest(const std::string& filename);
    void runGenerateFileDurationTest(const std::string& fileSize);
    void runInputDurationTest(const std::string& filename);
};

#endif 
