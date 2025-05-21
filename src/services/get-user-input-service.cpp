#include "abstract/get-user-input-service.h"

GetUserInputService::GetUserInputService(InputManagerRepositoryContract& inputManagerRepo)
    : inputManagerRepositoryContract(inputManagerRepo) {}

void GetUserInputService::execute(bool needsParameter) {
    try {
        InputManager inputManager;

        int sortingChoice;
        std::string fileSize;

        std::cout << "Is creating data files with students (0: false, 1: true): ";
        bool isCreatingDataFiles;
        std::cin >> isCreatingDataFiles;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input for testing mode");
        }
        inputManager.setIsCreatingDataFiles(isCreatingDataFiles);

        std::cout << "Enter Sorting Choice (0: SURNAME, 1: NAME, 2: FINAL_GRADE_WITH_AVERAGE, 3: FINAL_GRADE_WITH_MEDIAN): ";
        std::cin >> sortingChoice;
        if (sortingChoice < 0 || sortingChoice > 3 || std::cin.fail()) {
            throw std::invalid_argument("Invalid sorting choice");
        }
        inputManager.setSortingChoice(static_cast<InputManager::SortingChoice>(sortingChoice));

        int containerChoice;
        std::cout << "Enter Container Type (0: DEQUE, 1: VECTOR, 2: LIST): ";
        std::cin >> containerChoice;
        if (containerChoice < 0 || containerChoice > 2 || std::cin.fail()) {
            throw std::invalid_argument("Invalid container type choice");
        }
        inputManager.setChosenContainerType(static_cast<InputManager::ContainerType>(containerChoice));

        std::cout << "Enter Strategy Choice (0: STRATEGY1, 1: STRATEGY2): ";
        int strategyChoice;
        std::cin >> strategyChoice;
        if (strategyChoice < 0 || strategyChoice > 1 || std::cin.fail()) {
            throw std::invalid_argument("Invalid strategy choice");
        }
        inputManager.setStrategyChoice(static_cast<InputManager::StrategyChoice>(strategyChoice));

        std::cout << "Is Testing Rule of Five (0: false, 1: true): ";
        bool isTestingRuleOfFive;
        std::cin >> isTestingRuleOfFive;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input for whether testing rule of five");
        }
        inputManager.setIsTestingRuleOfFive(isTestingRuleOfFive);
        inputManagerRepositoryContract.setInputManager(inputManager);
        if (inputManager.getIsTestingRuleOfFive()) return;

        std::cout << "Is Testing Mode (0: false, 1: true): ";
        bool isTestingMode;
        std::cin >> isTestingMode;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input for testing mode");
        }
        inputManager.setIsTestingMode(isTestingMode);

        std::cout << "Is Data Read From File (0: false, 1: true): ";
        bool isDataReadFromFile;
        std::cin >> isDataReadFromFile;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input for data read from file");
        }
        inputManager.setIsDataReadFromFile(isDataReadFromFile);

        if (!inputManager.getIsDataReadFromFile()){
            std::cout << "Is Data Generated Automatically (0: false, 1: true): ";
            bool isDataGeneratedAutomatically;
            std::cin >> isDataGeneratedAutomatically;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input for data generated automatically");
            }
            inputManager.setIsDataGeneratedAutomatically(isDataGeneratedAutomatically);

            if (!inputManager.getIsDataGeneratedAutomatically()){
                std::cout << "Is Defining Students (0: false, 1: true): ";
                bool isDefiningStudents;
                std::cin >> isDefiningStudents;
                if (std::cin.fail()) {
                    throw std::invalid_argument("Invalid input for defining students");
                }
                inputManager.setIsDefiningStudents(isDefiningStudents);
            }
        }


        std::cout << "Is Printing Data To File (0: false, 1: true): ";
        bool isPrintingDataToFile;
        std::cin >> isPrintingDataToFile;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input for printing data to file");
        }
        inputManager.setIsPrintingDataToFile(isPrintingDataToFile);

        std::cout << "Enter File Size (1000, 10000, 100000, 1000000, 10000000): ";
        std::cin >> fileSize;
        if (!inputManager.setFileSize(fileSize)) {
            throw std::invalid_argument("Invalid file size");
        }

        inputManagerRepositoryContract.setInputManager(inputManager);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
