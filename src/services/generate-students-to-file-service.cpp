#include "abstract/generate-students-to-file-service.h"

GenerateStudentsToFileService::GenerateStudentsToFileService() {
    std::srand(std::time(nullptr));
}

int GenerateStudentsToFileService::getRandomGrade() {
    return std::rand() % 10 + 1;
}

void GenerateStudentsToFileService::execute(std::string fileSize) {
    try {
        std::string filename = "../text-files/students" + fileSize + ".txt";
        int numberOfStudents = std::stoi(fileSize);

        std::ofstream inputFile(filename);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        inputFile << std::left << std::setw(20) << "Vardas"
                  << std::left << std::setw(20) << "Pavarde"
                  << std::left << std::setw(10) << "ND1"
                  << std::left << std::setw(10) << "ND2"
                  << std::left << std::setw(10) << "ND3"
                  << std::left << std::setw(10) << "ND4"
                  << std::left << std::setw(10) << "ND5"
                  << std::left << std::setw(10) << "EGZ." << "\n";

        for (int i = 1; i <= numberOfStudents; i++) {
            inputFile << std::left << std::setw(20) << "VardasNR" + std::to_string(i)
                      << std::left << std::setw(20) << "PavardeNR" + std::to_string(i)
                      << std::left << std::setw(10) << getRandomGrade()
                      << std::left << std::setw(10) << getRandomGrade()
                      << std::left << std::setw(10) << getRandomGrade()
                      << std::left << std::setw(10) << getRandomGrade()
                      << std::left << std::setw(10) << getRandomGrade()
                      << std::left << std::setw(10) << getRandomGrade() << "\n";
        }

        inputFile.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
