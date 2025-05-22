#ifndef STUDENTS_VECTOR_REPOSITORY_CONTRACT_H
#define STUDENTS_VECTOR_REPOSITORY_CONTRACT_H

#include "../../models/abstract/student-model.h"
#include <vector>
#include <list>
#include <deque>
#include <variant>
#include "../../containers/my-vector-container.h"

using StudentContainer = std::variant<
    std::vector<Student>,
    std::list<Student>,
    std::deque<Student>,
    MyVector<Student>
>;

class StudentsRepositoryContract {
public:
    virtual ~StudentsRepositoryContract() = default;
    virtual void save(Student studentWithGradesVector) = 0;
    virtual StudentContainer getStudentWithGradesVector() = 0;
    virtual void sortData() = 0;
    virtual void clearData() = 0;
};

#endif 
