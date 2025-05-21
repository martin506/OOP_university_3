#include "abstract/input-manager-repository.h"

InputManager InputManagerRepository::getInputManager() {
    return inputManager;
}

void InputManagerRepository::setInputManager(InputManager updatedInputManager) {
    inputManager = updatedInputManager;
}
