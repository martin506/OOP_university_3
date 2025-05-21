#ifndef RULE_OF_FIVE_TEST_USECASE_H
#define RULE_OF_FIVE_TEST_USECASE_H

#include "../../../common/usecase-common.h"
class RuleOfFiveTestUseCase: UseCase<bool, void> {
public: 
    virtual void execute(bool needsParameter) = 0;
};

#endif