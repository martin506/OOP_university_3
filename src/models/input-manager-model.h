#ifndef INPUT_MANAGER_MODEL_H
#define INPUT_MANAGER_MODEL_H

#include <string>
#include <set>

struct InputManager {
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

    SortingChoice sortingChoice;
    ContainerType chosenContainerType;
    StrategyChoice strategyChoice;

    bool isCreatingDataFiles;
    bool isTestingMode;
    bool isDataReadFromFile;
    bool isDataGeneratedAutomatically;
    bool isDefiningStudents;
    bool isPrintingDataToFile;

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

private:
    std::string fileSize;
};

#endif
