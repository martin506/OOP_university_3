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
    InputManager();

    inline SortingChoice getSortingChoice() const { return sortingChoice; }
    inline void setSortingChoice(SortingChoice choice) { sortingChoice = choice; }
    inline ContainerType getChosenContainerType() const { return chosenContainerType; }
    inline void setChosenContainerType(ContainerType type) { chosenContainerType = type; }
    inline StrategyChoice getStrategyChoice() const { return strategyChoice; }
    inline void setStrategyChoice(StrategyChoice choice) { strategyChoice = choice; }
    inline bool getIsCreatingDataFiles() const { return isCreatingDataFiles; }
    inline void setIsCreatingDataFiles(bool value) { isCreatingDataFiles = value; }
    inline bool getIsTestingMode() const { return isTestingMode; }
    inline void setIsTestingMode(bool value) { isTestingMode = value; }
    inline bool getIsDataReadFromFile() const { return isDataReadFromFile; }
    inline void setIsDataReadFromFile(bool value) { isDataReadFromFile = value; }
    inline bool getIsDataGeneratedAutomatically() const { return isDataGeneratedAutomatically; }
    inline void setIsDataGeneratedAutomatically(bool value) { isDataGeneratedAutomatically = value; }
    inline bool getIsDefiningStudents() const { return isDefiningStudents; }
    inline void setIsDefiningStudents(bool value) { isDefiningStudents = value; }
    inline bool getIsPrintingDataToFile() const { return isPrintingDataToFile; }
    inline void setIsPrintingDataToFile(bool value) { isPrintingDataToFile = value; }

    bool setFileSize(const std::string& size);
    std::string getFileSize() const;
};

#endif
