#ifndef INPUT_DURATION_TEST_H
#define INPUT_DURATION_TEST_H

#include "../../services/usecases/save-students-data-from-file-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"
#include <string>

class InputDurationTest
{
private:
    StudentsRepositoryContract *studentsRepository;
    SaveStudentsDataFromFileUseCase *saveService;

public:
    InputDurationTest(StudentsRepositoryContract *studentsRepository, SaveStudentsDataFromFileUseCase *saveService);
    void testInputDuration(const std::string &fileName);
};

#endif
