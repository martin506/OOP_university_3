#ifndef GENERATE_STUDENTS_BY_HAND_SERVICE_H
#define GENERATE_STUDENTS_BY_HAND_SERVICE_H

#include "../usecases/generate-students-by-hand-usecase.h"
#include "../../repositories/contracts/students-repository-contract.h"
#include <vector>
#include <string>

class GenerateStudentsByHandService : public GenerateStudentsByHandUseCase {
private:
    StudentsRepositoryContract* studentsRepository;

public:
    GenerateStudentsByHandService(StudentsRepositoryContract* repo);
    void execute(bool needsParameter) override;
};

#endif 
