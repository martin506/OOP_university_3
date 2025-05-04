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
            Student student;

            std::string name, surname;
            int examGrade;

            lineStream >> name >> surname;
            int grade;
            while (lineStream >> grade) {
                student.addGrade(grade);
            }

            if (!student.getGrades().empty()) {
                examGrade = student.getGrades().back();
                student.removeLastGrade();
            }

            student.setName(name);
            student.setSurname(surname);
            student.setExamGrade(examGrade);
            student.setFinalGradeWithAverage(student.calculateAverage());
            student.setFinalGradeWithMedian(student.calculateMedian());
            studentsRepository.save(student);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
