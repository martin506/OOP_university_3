#include "abstract/print-students-to-file-service.h"

PrintStudentsToFileService::PrintStudentsToFileService(StudentsRepositoryContract &repo)
    : studentsRepository(repo) {}

void PrintStudentsToFileService::execute(std::string fileName)
{
    try
    {
        std::ofstream outputFile(fileName);
        if (!outputFile.is_open())
        {
            throw std::runtime_error("Failed to open file: " + fileName);
        }

        outputFile << std::left << std::setw(20) << "Name"
                   << std::left << std::setw(20) << "Surname"
                   << std::left << std::setw(10) << "Exam"
                   << std::left << std::setw(15) << "Avg Grade"
                   << std::left << std::setw(15) << "Med Grade" << "\n";

        StudentContainer students = studentsRepository.getStudentWithGradesVector();

        std::visit([&outputFile](auto &&container)
            {
                for (const auto& studentWithGrades : container) {
                    outputFile << std::left << std::setw(20) << studentWithGrades.getStudent().getName()
                                << std::left << std::setw(20) << studentWithGrades.getStudent().getSurname()
                                << std::left << std::setw(10) << studentWithGrades.getStudent().getExamGrade()
                                << std::left << std::setw(15) << studentWithGrades.getStudent().getFinalGradeWithAverage()
                                << std::left << std::setw(15) << studentWithGrades.getStudent().getFinalGradeWithMedian() << "\n";
                } }, students);

        outputFile.close();
        std::cout << "Student data printed to file successfully. file name: " << fileName << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
