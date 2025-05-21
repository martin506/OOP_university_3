#include "abstract/sort-students-service.h"

SortStudentsService::SortStudentsService(StudentsRepositoryContract& studentsRepository)
    : studentsRepository(studentsRepository) {}

void SortStudentsService::execute(bool needsParameter) {
    studentsRepository.sortData();
}