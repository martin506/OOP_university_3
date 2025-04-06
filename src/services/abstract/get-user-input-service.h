#ifndef GET_USER_INPUT_SERVICE_H
#define GET_USER_INPUT_SERVICE_H

#include "../usecases/get-user-input-usecase.h"
#include "../../repositories/contracts/input-manager-repository-contract.h"
#include <iostream>
#include <stdexcept>

class GetUserInputService : public GetUserInputUseCase {
private:
    InputManagerRepositoryContract& inputManagerRepositoryContract;

public:
    GetUserInputService(InputManagerRepositoryContract& inputManagerRepo);
    void execute(bool needsParameter) override;
};

#endif