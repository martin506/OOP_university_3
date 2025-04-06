#include "abstract/tests-controller.h"

TestsController::TestsController(
    StudentsRepositoryContract& studentsRepo,
    GenerateStudentsToFileUseCase& generateService,
    SaveStudentsDataFromFileUseCase& saveService,
    SortStudentsUseCase& sortService,
    SortStudentsToBadAndGoodUseCase& sortToBadAndGoodService,
    PrintStudentsToFileUseCase& printGoodStudentsService,
    PrintStudentsToFileUseCase& printBadStudentsService
) : generateFileDurationTest(generateService),
    moduleTest(saveService, sortService, sortToBadAndGoodService, printGoodStudentsService, printBadStudentsService),
    inputDurationTest(studentsRepo, saveService),
    studentsRepo(studentsRepo),
    generateService(generateService),
    saveService(saveService),
    sortService(sortService),
    sortToBadAndGoodService(sortToBadAndGoodService),
    printGoodStudentsService(printGoodStudentsService),
    printBadStudentsService(printBadStudentsService) {}

void TestsController::runModuleTest(const std::string& filename) {
    moduleTest.testModule(filename);
}

void TestsController::runGenerateFileDurationTest(const std::string& fileSize) {
    generateFileDurationTest.testGenerateFileDuration(fileSize);
}

void TestsController::runInputDurationTest(const std::string& filename) {
    inputDurationTest.testInputDuration(filename);
}
