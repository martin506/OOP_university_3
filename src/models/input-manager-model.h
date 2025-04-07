#ifndef INPUT_MANAGER_MODEL_H
#define INPUT_MANAGER_MODEL_H

#include <string>
#include <set>

class InputManager {
public:
    enum SortingChoice {
        SURNAME,
        NAME,
        FINAL_GRADE_WITH_AVERAGE,
        FINAL_GRADE_WITH_MEDIAN
    };

    enum ContainerType {
        DEQUE,
        VECTOR,
        LIST
    };

    enum StrategyChoice {
        STRATEGY1,
        STRATEGY2
    };

private:
    SortingChoice sortingChoice;
    ContainerType chosenContainerType;
    StrategyChoice strategyChoice;

    bool isCreatingDataFiles;
    bool isTestingMode;
    bool isDataReadFromFile;
    bool isDataGeneratedAutomatically;
    bool isDefiningStudents;
    bool isPrintingDataToFile;

    std::string fileSize;

public:
    InputManager()
        : sortingChoice(SURNAME), chosenContainerType(VECTOR), strategyChoice(STRATEGY1),
          isCreatingDataFiles(false), isTestingMode(false), isDataReadFromFile(false),
          isDataGeneratedAutomatically(false), isDefiningStudents(false), isPrintingDataToFile(false) {}

    SortingChoice getSortingChoice() const {
        return sortingChoice;
    }

    void setSortingChoice(SortingChoice choice) {
        sortingChoice = choice;
    }

    ContainerType getChosenContainerType() const {
        return chosenContainerType;
    }

    void setChosenContainerType(ContainerType type) {
        chosenContainerType = type;
    }

    StrategyChoice getStrategyChoice() const {
        return strategyChoice;
    }

    void setStrategyChoice(StrategyChoice choice) {
        strategyChoice = choice;
    }

    bool getIsCreatingDataFiles() const {
        return isCreatingDataFiles;
    }

    void setIsCreatingDataFiles(bool value) {
        isCreatingDataFiles = value;
    }

    bool getIsTestingMode() const {
        return isTestingMode;
    }

    void setIsTestingMode(bool value) {
        isTestingMode = value;
    }

    bool getIsDataReadFromFile() const {
        return isDataReadFromFile;
    }

    void setIsDataReadFromFile(bool value) {
        isDataReadFromFile = value;
    }

    bool getIsDataGeneratedAutomatically() const {
        return isDataGeneratedAutomatically;
    }

    void setIsDataGeneratedAutomatically(bool value) {
        isDataGeneratedAutomatically = value;
    }

    bool getIsDefiningStudents() const {
        return isDefiningStudents;
    }

    void setIsDefiningStudents(bool value) {
        isDefiningStudents = value;
    }

    bool getIsPrintingDataToFile() const {
        return isPrintingDataToFile;
    }

    void setIsPrintingDataToFile(bool value) {
        isPrintingDataToFile = value;
    }

    bool setFileSize(const std::string& size) {
        static const std::set<std::string> viableSizes = {"1000", "10000", "100000", "1000000", "10000000"};
        if (viableSizes.find(size) != viableSizes.end()) {
            fileSize = size;
            return true;
        }
        return false;
    }

    std::string getFileSize() const {
        return fileSize;
    }
};

#endif
