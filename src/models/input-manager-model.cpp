#include "input-manager-model.h"

InputManager::InputManager()
    : sortingChoice(SURNAME), chosenContainerType(VECTOR), strategyChoice(STRATEGY1),
      isCreatingDataFiles(false), isTestingMode(false), isDataReadFromFile(false),
      isDataGeneratedAutomatically(false), isDefiningStudents(false), isPrintingDataToFile(false) {}

bool InputManager::setFileSize(const std::string& size) {
    static const std::set<std::string> viableSizes = {"1000", "10000", "100000", "1000000", "10000000"};
    if (viableSizes.find(size) != viableSizes.end()) {
        fileSize = size;
        return true;
    }
    return false;
}

std::string InputManager::getFileSize() const {
    return fileSize;
}
