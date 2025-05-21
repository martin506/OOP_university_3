#ifndef GENERATE_STUDENTS_TO_FILE_SERVICE_H
#define GENERATE_STUDENTS_TO_FILE_SERVICE_H

#include "../usecases/generate-students-to-file-usecase.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <ctime>

class GenerateStudentsToFileService : public GenerateStudentsToFileUseCase {
private:
    int getRandomGrade();

public:
    GenerateStudentsToFileService();
    void execute(std::string fileSize) override;
};

#endif
