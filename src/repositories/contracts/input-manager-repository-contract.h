#ifndef INPUT_MANAGER_REPOSITORY_CONTRACT_H
#define INPUT_MANAGER_REPOSITORY_CONTRACT_H

#include "../../models/abstract/input-manager-model.h"

class InputManagerRepositoryContract {
private:
    InputManager inputManager;

public:
    virtual ~InputManagerRepositoryContract() = default;
    virtual InputManager getInputManager() = 0;
    virtual void setInputManager(InputManager updatedInputManager) = 0;
};

#endif