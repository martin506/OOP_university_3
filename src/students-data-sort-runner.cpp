#include "abstract/students-data-sort-runner.h"

StudentsDataSortRunner::StudentsDataSortRunner()
    : inputManagerRepo(new InputManagerRepository()),
      studentsRepo(new StudentsVectorRepository(inputManagerRepo)),
      goodStudentsRepo(new StudentsVectorRepository(inputManagerRepo)),
      badStudentsRepo(new StudentsVectorRepository(inputManagerRepo)),
      printStudentsToFileService(new PrintStudentsToFileService(studentsRepo)),
      printGoodStudentsToFileService(new PrintStudentsToFileService(goodStudentsRepo)),
      printBadStudentsToFileService(new PrintStudentsToFileService(badStudentsRepo)),
      createStudentsAutomaticallyService(new CreateStudentsAutomaticallyService(studentsRepo)),
      generateStudentsByHandService(new GenerateStudentsByHandService(studentsRepo)),
      generateStudentsToFileService(new GenerateStudentsToFileService()),
      getUserInputService(new GetUserInputService(inputManagerRepo)),
      printStudentsToConsoleService(new PrintStudentsToConsoleService(studentsRepo)),
      saveStudentsDataFromFileService(new SaveStudentsDataFromFileService(studentsRepo)),
      sortStudentsService(new SortStudentsService(studentsRepo)),
      sortStudentsToBadAndGoodService(new SortStudentsToBadAndGoodService(goodStudentsRepo, badStudentsRepo, studentsRepo)),
      sortStudentsToBadAndGoodServiceStrategy2(new SortStudentsToBadAndGoodServiceStrategy2(badStudentsRepo, studentsRepo)),
      testsController(studentsRepo, generateStudentsToFileService, saveStudentsDataFromFileService, sortStudentsService, sortStudentsToBadAndGoodService, printGoodStudentsToFileService, printBadStudentsToFileService) {}

void StudentsDataSortRunner::updateServices()
{
    delete printStudentsToFileService;
    delete printGoodStudentsToFileService;
    delete printBadStudentsToFileService;
    delete createStudentsAutomaticallyService;
    delete generateStudentsByHandService;
    delete generateStudentsToFileService;
    delete getUserInputService;
    delete printStudentsToConsoleService;
    delete saveStudentsDataFromFileService;
    delete sortStudentsService;
    delete sortStudentsToBadAndGoodService;
    delete sortStudentsToBadAndGoodServiceStrategy2;

    printStudentsToFileService = new PrintStudentsToFileService(studentsRepo);
    printGoodStudentsToFileService = new PrintStudentsToFileService(goodStudentsRepo);
    printBadStudentsToFileService = new PrintStudentsToFileService(badStudentsRepo);
    createStudentsAutomaticallyService = new CreateStudentsAutomaticallyService(studentsRepo);
    generateStudentsByHandService = new GenerateStudentsByHandService(studentsRepo);
    generateStudentsToFileService = new GenerateStudentsToFileService();
    getUserInputService = new GetUserInputService(inputManagerRepo);
    printStudentsToConsoleService = new PrintStudentsToConsoleService(studentsRepo);
    saveStudentsDataFromFileService = new SaveStudentsDataFromFileService(studentsRepo);
    sortStudentsService = new SortStudentsService(studentsRepo);
    sortStudentsToBadAndGoodService = new SortStudentsToBadAndGoodService(goodStudentsRepo, badStudentsRepo, studentsRepo);
    sortStudentsToBadAndGoodServiceStrategy2 = new SortStudentsToBadAndGoodServiceStrategy2(badStudentsRepo, studentsRepo);
    testsController = TestsController(studentsRepo, generateStudentsToFileService, saveStudentsDataFromFileService, sortStudentsService, sortStudentsToBadAndGoodService, printGoodStudentsToFileService, printBadStudentsToFileService);
}

void StudentsDataSortRunner::useVectors()
{
    delete studentsRepo;
    delete goodStudentsRepo;
    delete badStudentsRepo;

    studentsRepo = new StudentsVectorRepository(inputManagerRepo);
    goodStudentsRepo = new StudentsVectorRepository(inputManagerRepo);
    badStudentsRepo = new StudentsVectorRepository(inputManagerRepo);

    updateServices();
}

void StudentsDataSortRunner::useLists()
{
    delete studentsRepo;
    delete goodStudentsRepo;
    delete badStudentsRepo;

    studentsRepo = new StudentsListRepository(inputManagerRepo);
    goodStudentsRepo = new StudentsListRepository(inputManagerRepo);
    badStudentsRepo = new StudentsListRepository(inputManagerRepo);

    updateServices();
}

void StudentsDataSortRunner::useDeques()
{
    delete studentsRepo;
    delete goodStudentsRepo;
    delete badStudentsRepo;

    studentsRepo = new StudentsDequeRepository(inputManagerRepo);
    goodStudentsRepo = new StudentsDequeRepository(inputManagerRepo);
    badStudentsRepo = new StudentsDequeRepository(inputManagerRepo);

    updateServices();
}

void StudentsDataSortRunner::run()
{
    getUserInputService->execute(false);
    InputManager inputManager = inputManagerRepo->getInputManager();

    switch (inputManager.chosenContainerType)
    {
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

    if (inputManager.isTestingMode)
    {
        // testsController.runGenerateFileDurationTest(filename);
        testsController.runInputDurationTest(filename);
        testsController.runModuleTest(filename);
        return;
    }

    if (inputManager.isDataReadFromFile)
    {
        saveStudentsDataFromFileService->execute(filename);
    }
    else if (inputManager.isDataGeneratedAutomatically)
    {
        createStudentsAutomaticallyService->execute(1000);
    }
    else if (inputManager.isDefiningStudents)
    {
        generateStudentsByHandService->execute(false);
    }
    else
    {
        return;
    }

    switch (inputManager.strategyChoice)
    {
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

    if (inputManager.isPrintingDataToFile)
    {
        switch (inputManager.strategyChoice)
        {
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
    }
    else
    {
        printStudentsToConsoleService->execute(false);
    }

    studentsRepo->clearData();
    goodStudentsRepo->clearData();
    badStudentsRepo->clearData();
}
