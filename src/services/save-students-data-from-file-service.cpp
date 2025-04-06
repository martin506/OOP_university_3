#include "abstract/save-students-data-from-file-service.h"

SaveStudentsDataFromFileService::SaveStudentsDataFromFileService(StudentsRepositoryContract& repo)
    : studentsRepository(repo) {}

void SaveStudentsDataFromFileService::execute(std::string filename) {
    try {
        std::string filePath = "../text-files/students" + filename + ".txt";

        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::invalid_argument("Failed to open file: " + filePath);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();

        std::string line;
        std::getline(buffer, line); 

        while (std::getline(buffer, line)) {
            std::istringstream lineStream(line);
            StudentWithGradesVector studentWithGrades;

            std::string name, surname;
            int examGrade;

            lineStream >> name >> surname;
            int grade;
            while (lineStream >> grade) {
                studentWithGrades.grades.push_back(grade);
            }

            if (!studentWithGrades.grades.empty()) {
                examGrade = studentWithGrades.grades.back();
                studentWithGrades.grades.pop_back();
            }

            Student student = Student(name, surname, examGrade, studentWithGrades.calculateAverage(), studentWithGrades.calculateMedian());
            studentWithGrades.student = student;
            studentsRepository.save(studentWithGrades);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
