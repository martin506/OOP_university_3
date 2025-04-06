#ifndef STUDENTS_DEQUE_REPOSITORY_H
#define STUDENTS_DEQUE_REPOSITORY_H

#include "../contracts/students-repository-contract.h"
#include "../contracts/input-manager-repository-contract.h"
#include <deque>
#include <algorithm>
#include <stdexcept>

class StudentsDequeRepository : public StudentsRepositoryContract {
private:
    std::deque<StudentWithGradesVector> students;
    InputManagerRepositoryContract& inputManagerRepository; 

public:
    explicit StudentsDequeRepository(InputManagerRepositoryContract& inputManagerRepository);
    ~StudentsDequeRepository() override = default;

    void save(StudentWithGradesVector studentWithGradesVector) override;
    StudentContainer getStudentWithGradesVector() override;
    void sortData() override;
    void clearData() override;
};

#endif