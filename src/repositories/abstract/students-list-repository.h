#ifndef STUDENTS_LIST_REPOSITORY_H
#define STUDENTS_LIST_REPOSITORY_H

#include "../contracts/students-repository-contract.h"
#include "../contracts/input-manager-repository-contract.h"
#include "../../models/abstract/student-with-grades-vector-model.h"
#include <list>
#include <stdexcept>

class StudentsListRepository : public StudentsRepositoryContract {
private:
    std::list<StudentWithGradesVector> students;
    InputManagerRepositoryContract& inputManagerRepository;

public:
    explicit StudentsListRepository(InputManagerRepositoryContract& inputManagerRepository);
    ~StudentsListRepository() override = default;

    void save(StudentWithGradesVector studentWithGradesVector) override;
    StudentContainer getStudentWithGradesVector() override;
    void sortData() override;
    void clearData() override;
};

#endif
