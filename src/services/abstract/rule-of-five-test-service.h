#ifndef RULE_OF_FIVE_TEST_SERVICE_H
#define RULE_OF_FIVE_TEST_SERVICE_H

#include "../usecases/rule-of-five-test-usecase.h"
#include "../../models/abstract/student-model.h"

class RuleOfFiveTestService : public RuleOfFiveTestUseCase
{
public:
    RuleOfFiveTestService();
    void execute(bool needsParameter) override;
};

#endif