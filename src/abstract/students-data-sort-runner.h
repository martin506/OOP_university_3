#ifndef STUDENTS_DATA_SORT_RUNNER_H
#define STUDENTS_DATA_SORT_RUNNER_H

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

class StudentsDataSortRunner {
private:
    InputManagerRepositoryContract* inputManagerRepo;
    StudentsRepositoryContract* studentsRepo;
    StudentsRepositoryContract* goodStudentsRepo;
    StudentsRepositoryContract* badStudentsRepo;

    PrintStudentsToFileUseCase* printStudentsToFileService;
    PrintStudentsToFileUseCase* printGoodStudentsToFileService;
    PrintStudentsToFileUseCase* printBadStudentsToFileService;

    CreateStudentsAutomaticallyUseCase* createStudentsAutomaticallyService;
    GenerateStudentsByHandUseCase* generateStudentsByHandService;
    GenerateStudentsToFileUseCase* generateStudentsToFileService;
    GetUserInputUseCase* getUserInputService;
    PrintStudentsToConsoleUseCase* printStudentsToConsoleService;
    SaveStudentsDataFromFileUseCase* saveStudentsDataFromFileService;
    SortStudentsUseCase* sortStudentsService;
    SortStudentsToBadAndGoodUseCase* sortStudentsToBadAndGoodService;
    SortStudentsToBadAndGoodUseCase* sortStudentsToBadAndGoodServiceStrategy2;

    TestsController testsController;

public:
    StudentsDataSortRunner();
    void run();
    void useVectors();
    void useDeques();
    void useLists();
    void updateServices();
};

#endif 