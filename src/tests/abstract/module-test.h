#ifndef MODULE_TEST_H
#define MODULE_TEST_H

#include "../../services/usecases/save-students-data-from-file-usecase.h"
#include "../../services/usecases/sort-students-usecase.h"
#include "../../services/usecases/sort-students-to-bad-and-good-usecase.h"
#include "../../services/usecases/print-students-to-file-usecase.h"
#include <string>

class ModuleTest {
private:
    SaveStudentsDataFromFileUseCase& saveService;
    SortStudentsUseCase& sortService;
    SortStudentsToBadAndGoodUseCase& sortToBadAndGoodService;
    PrintStudentsToFileUseCase& printGoodStudentsService;
    PrintStudentsToFileUseCase& printBadStudentsService;

public:
    ModuleTest(
        SaveStudentsDataFromFileUseCase& saveService,
        SortStudentsUseCase& sortService,
        SortStudentsToBadAndGoodUseCase& sortToBadAndGoodService,
        PrintStudentsToFileUseCase& printGoodStudentsService,
        PrintStudentsToFileUseCase& printBadStudentsService
    );

    void testModule(const std::string& filename);
};

#endif
