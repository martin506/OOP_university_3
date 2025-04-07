#include "abstract/students-data-sort-runner.h"

StudentsDataSortRunner::StudentsDataSortRunner()
    : inputManagerRepo(std::make_unique<InputManagerRepository>()),
      studentsRepo(std::make_unique<StudentsVectorRepository>(*inputManagerRepo)),
      goodStudentsRepo(std::make_unique<StudentsVectorRepository>(*inputManagerRepo)),
      badStudentsRepo(std::make_unique<StudentsVectorRepository>(*inputManagerRepo)),
      printStudentsToFileService(std::make_unique<PrintStudentsToFileService>(*studentsRepo)),
      printGoodStudentsToFileService(std::make_unique<PrintStudentsToFileService>(*goodStudentsRepo)),
      printBadStudentsToFileService(std::make_unique<PrintStudentsToFileService>(*badStudentsRepo)),
      createStudentsAutomaticallyService(std::make_unique<CreateStudentsAutomaticallyService>(*studentsRepo)),
      generateStudentsByHandService(std::make_unique<GenerateStudentsByHandService>(*studentsRepo)),
      generateStudentsToFileService(std::make_unique<GenerateStudentsToFileService>()),
      getUserInputService(std::make_unique<GetUserInputService>(*inputManagerRepo)),
      printStudentsToConsoleService(std::make_unique<PrintStudentsToConsoleService>(*studentsRepo)),
      saveStudentsDataFromFileService(std::make_unique<SaveStudentsDataFromFileService>(*studentsRepo)),
      sortStudentsService(std::make_unique<SortStudentsService>(*studentsRepo)),
      sortStudentsToBadAndGoodService(std::make_unique<SortStudentsToBadAndGoodService>(*goodStudentsRepo, *badStudentsRepo, *studentsRepo)),
      sortStudentsToBadAndGoodServiceStrategy2(std::make_unique<SortStudentsToBadAndGoodServiceStrategy2>(*badStudentsRepo, *studentsRepo)),
      testsController(std::make_unique<TestsController>(*studentsRepo, *generateStudentsToFileService, *saveStudentsDataFromFileService, *sortStudentsService, *sortStudentsToBadAndGoodService, *printGoodStudentsToFileService, *printBadStudentsToFileService)) {}

void StudentsDataSortRunner::updateServices() {
    printStudentsToFileService = std::make_unique<PrintStudentsToFileService>(*studentsRepo);
    printGoodStudentsToFileService = std::make_unique<PrintStudentsToFileService>(*goodStudentsRepo);
    printBadStudentsToFileService = std::make_unique<PrintStudentsToFileService>(*badStudentsRepo);
    createStudentsAutomaticallyService = std::make_unique<CreateStudentsAutomaticallyService>(*studentsRepo);
    generateStudentsByHandService = std::make_unique<GenerateStudentsByHandService>(*studentsRepo);
    generateStudentsToFileService = std::make_unique<GenerateStudentsToFileService>();
    getUserInputService = std::make_unique<GetUserInputService>(*inputManagerRepo);
    printStudentsToConsoleService = std::make_unique<PrintStudentsToConsoleService>(*studentsRepo);
    saveStudentsDataFromFileService = std::make_unique<SaveStudentsDataFromFileService>(*studentsRepo);
    sortStudentsService = std::make_unique<SortStudentsService>(*studentsRepo);
    sortStudentsToBadAndGoodService = std::make_unique<SortStudentsToBadAndGoodService>(*goodStudentsRepo, *badStudentsRepo, *studentsRepo);
    sortStudentsToBadAndGoodServiceStrategy2 = std::make_unique<SortStudentsToBadAndGoodServiceStrategy2>(*badStudentsRepo, *studentsRepo);
    testsController = std::make_unique<TestsController>(*studentsRepo, *generateStudentsToFileService, *saveStudentsDataFromFileService, *sortStudentsService, *sortStudentsToBadAndGoodService, *printGoodStudentsToFileService, *printBadStudentsToFileService);
}

void StudentsDataSortRunner::useVectors() {
    studentsRepo = std::make_unique<StudentsVectorRepository>(*inputManagerRepo);
    goodStudentsRepo = std::make_unique<StudentsVectorRepository>(*inputManagerRepo);
    badStudentsRepo = std::make_unique<StudentsVectorRepository>(*inputManagerRepo);
    updateServices();
}

void StudentsDataSortRunner::useLists() {
    studentsRepo = std::make_unique<StudentsListRepository>(*inputManagerRepo);
    goodStudentsRepo = std::make_unique<StudentsListRepository>(*inputManagerRepo);
    badStudentsRepo = std::make_unique<StudentsListRepository>(*inputManagerRepo);
    updateServices();
}

void StudentsDataSortRunner::useDeques() {
    studentsRepo = std::make_unique<StudentsDequeRepository>(*inputManagerRepo);
    goodStudentsRepo = std::make_unique<StudentsDequeRepository>(*inputManagerRepo);
    badStudentsRepo = std::make_unique<StudentsDequeRepository>(*inputManagerRepo);
    updateServices();
}

void StudentsDataSortRunner::run() {
    getUserInputService->execute(false);
    InputManager inputManager = inputManagerRepo->getInputManager();

    if (inputManager.getIsCreatingDataFiles()) {
        for (int i = 3; i < 7; i++) {
            std::string studentId = "1" + std::string(i, '0');
            generateStudentsToFileService->execute(studentId);
        }
        return;
    }

    switch (inputManager.getChosenContainerType()) {
        case InputManager::DEQUE:
            useDeques();
            break;
        case InputManager::VECTOR:
            useVectors();
            break;
        case InputManager::LIST:
            useLists();
            break;
        default:
            throw std::invalid_argument("Invalid container type");
    }

    std::string filename = inputManager.getFileSize();

    if (inputManager.getIsTestingMode()) {
        testsController->runInputDurationTest(filename);
        testsController->runModuleTest(filename);
        return;
    }

    if (inputManager.getIsDataReadFromFile()) {
        saveStudentsDataFromFileService->execute(filename);
    } else if (inputManager.getIsDataGeneratedAutomatically()) {
        createStudentsAutomaticallyService->execute(1000);
    } else if (inputManager.getIsDefiningStudents()) {
        generateStudentsByHandService->execute(false);
    } else {
        return;
    }

    switch (inputManager.getStrategyChoice()) {
        case InputManager::STRATEGY1:
            sortStudentsToBadAndGoodService->execute(false);
            break;
        case InputManager::STRATEGY2:
            sortStudentsToBadAndGoodServiceStrategy2->execute(false);
            break;
        default:
            sortStudentsToBadAndGoodService->execute(false);
            break;
    }

    sortStudentsService->execute(false);

    sortStudentsToBadAndGoodServiceStrategy2->execute(false);

    if (inputManager.getIsPrintingDataToFile()) {
        switch (inputManager.getStrategyChoice()) {
            case InputManager::STRATEGY1:
                printStudentsToFileService->execute("../text-files/output.txt");
                printGoodStudentsToFileService->execute("../text-files/good-students.txt");
                printBadStudentsToFileService->execute("../text-files/bad-students.txt");
                break;
            case InputManager::STRATEGY2:
                printStudentsToFileService->execute("../text-files/good-students.txt");
                printBadStudentsToFileService->execute("../text-files/bad-students.txt");
                break;
            default:
                printStudentsToFileService->execute("../text-files/output.txt");
                printGoodStudentsToFileService->execute("../text-files/good-students.txt");
                printBadStudentsToFileService->execute("../text-files/bad-students.txt");
                break;
        }
    } else {
        printStudentsToConsoleService->execute(false);
    }

    studentsRepo->clearData();
    goodStudentsRepo->clearData();
    badStudentsRepo->clearData();
}
