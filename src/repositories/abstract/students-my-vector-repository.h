#ifndef STUDENTS_MY_VECTOR_REPOSITORY_H
#define STUDENTS_MY_VECTOR_REPOSITORY_H

#include "../contracts/students-repository-contract.h"
#include "../contracts/input-manager-repository-contract.h"
#include <algorithm>
#include <iostream>

class StudentsMyVectorRepository : public StudentsRepositoryContract {
private:
    MyVector<Student> students;
    InputManagerRepositoryContract& inputManagerRepository;
public:
    explicit StudentsMyVectorRepository(InputManagerRepositoryContract& inputManagerRepository);
    ~StudentsMyVectorRepository() override = default;

    void save(Student studentWithGradesVector) override;
    StudentContainer getStudentWithGradesVector() override;
    void sortData() override;
    void clearData() override;
};

#endif // STUDENTS_MY_VECTOR_REPOSITORY_H