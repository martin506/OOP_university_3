#ifndef GET_USER_INPUT_USECASE_H
#define GET_USER_INPUT_USECASE_H

#include "../../../common/usecase-common.h"

class GetUserInputUseCase: UseCase<bool, void> {
    public:
        virtual void execute(bool needsParameter) = 0;
};

#endif