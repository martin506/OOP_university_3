#ifndef STUDENTS_VECTOR_REPOSITORY_CONTRACT_H
#define STUDENTS_VECTOR_REPOSITORY_CONTRACT_H

#include "../../models/abstract/student-with-grades-vector-model.h"
#include <vector>
#include <list>
#include <deque>
#include <variant>

using StudentContainer = std::variant<
    std::vector<StudentWithGradesVector>,
    std::list<StudentWithGradesVector>,
    std::deque<StudentWithGradesVector>
>;

class StudentsRepositoryContract {
public:
    virtual ~StudentsRepositoryContract() = default;
    virtual void save(StudentWithGradesVector studentWithGradesVector) = 0;
    virtual StudentContainer getStudentWithGradesVector() = 0;
    virtual void sortData() = 0;
    virtual void clearData() = 0;
};

#endif 
