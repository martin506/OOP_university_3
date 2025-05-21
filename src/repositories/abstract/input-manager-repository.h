#ifndef INPUT_MANAGER_REPOSITORY_H
#define INPUT_MANAGER_REPOSITORY_H

#include "../contracts/input-manager-repository-contract.h"

class InputManagerRepository : public InputManagerRepositoryContract {
private:
    InputManager inputManager;

public:
    InputManager getInputManager() override;
    void setInputManager(InputManager updatedInputManager) override;
};

#endif 