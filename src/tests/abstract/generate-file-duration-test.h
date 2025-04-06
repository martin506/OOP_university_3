#ifndef GENERATE_FILE_DURATION_TEST_H
#define GENERATE_FILE_DURATION_TEST_H

#include "../../services/usecases/generate-students-to-file-usecase.h"
#include <string>

class GenerateFileDurationTest {
private:
    GenerateStudentsToFileUseCase* generateService;

public:
    GenerateFileDurationTest(GenerateStudentsToFileUseCase* generateService);
    void testGenerateFileDuration(const std::string& fileSize);
};

#endif 
