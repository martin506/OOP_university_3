#ifndef STUDENTS_DATA_SORT_RUNNER_H
#define STUDENTS_DATA_SORT_RUNNER_H

#include <memory>

#include "../repositories/contracts/input-manager-repository-contract.h"
#include "../repositories/abstract/input-manager-repository.h"
#include "../repositories/contracts/students-repository-contract.h"

#include "../repositories/abstract/students-vector-repository.h"
#include "../repositories/abstract/students-list-repository.h"
#include "../repositories/abstract/students-deque-repository.h"

#include "../services/usecases/create-students-automatically-usecase.h"
#include "../services/abstract/create-students-automatically-service.h"
#include "../services/usecases/generate-students-by-hand-usecase.h"
#include "../services/abstract/generate-students-by-hand-service.h"
#include "../services/usecases/generate-students-to-file-usecase.h"
#include "../services/abstract/generate-students-to-file-service.h"
#include "../services/usecases/get-user-input-usecase.h"
#include "../services/abstract/get-user-input-service.h"
#include "../services/usecases/print-students-to-console-usecase.h"
#include "../services/abstract/print-students-to-console-service.h"
#include "../services/usecases/print-students-to-file-usecase.h"
#include "../services/abstract/print-students-to-file-service.h"
#include "../services/usecases/save-students-data-from-file-usecase.h"
#include "../services/abstract/save-students-data-from-file-service.h"
#include "../services/usecases/sort-students-usecase.h"
#include "../services/abstract/sort-students-service.h"
#include "../services/usecases/sort-students-to-bad-and-good-usecase.h"
#include "../services/abstract/sort-students-to-bad-and-good-service.h"
#include "../services/abstract/sort-students-to-bad-and-good-strategy-2-service.h"

#include "../tests/abstract/tests-controller.h"

class StudentsDataSortRunner
{
private:
    std::unique_ptr<InputManagerRepositoryContract> inputManagerRepo;
    std::unique_ptr<StudentsRepositoryContract> studentsRepo;
    std::unique_ptr<StudentsRepositoryContract> goodStudentsRepo;
    std::unique_ptr<StudentsRepositoryContract> badStudentsRepo;

    std::unique_ptr<PrintStudentsToFileUseCase> printStudentsToFileService;
    std::unique_ptr<PrintStudentsToFileUseCase> printGoodStudentsToFileService;
    std::unique_ptr<PrintStudentsToFileUseCase> printBadStudentsToFileService;

    std::unique_ptr<CreateStudentsAutomaticallyUseCase> createStudentsAutomaticallyService;
    std::unique_ptr<GenerateStudentsByHandUseCase> generateStudentsByHandService;
    std::unique_ptr<GenerateStudentsToFileUseCase> generateStudentsToFileService;
    std::unique_ptr<GetUserInputUseCase> getUserInputService;
    std::unique_ptr<PrintStudentsToConsoleUseCase> printStudentsToConsoleService;
    std::unique_ptr<SaveStudentsDataFromFileUseCase> saveStudentsDataFromFileService;
    std::unique_ptr<SortStudentsUseCase> sortStudentsService;
    std::unique_ptr<SortStudentsToBadAndGoodUseCase> sortStudentsToBadAndGoodService;
    std::unique_ptr<SortStudentsToBadAndGoodUseCase> sortStudentsToBadAndGoodServiceStrategy2;

    std::unique_ptr<TestsController> testsController;
    
public:
    StudentsDataSortRunner();
    void run();
    void useVectors();
    void useDeques();
    void useLists();
    void updateServices();
};

#endif