#include "abstract/input-duration-test.h"
#include <chrono>
#include <fstream>
#include <iostream>

InputDurationTest::InputDurationTest(StudentsRepositoryContract& studentsRepository, SaveStudentsDataFromFileUseCase& saveService)
    : studentsRepository(studentsRepository), saveService(saveService) {}

void InputDurationTest::testInputDuration(const std::string& fileName) {
    double sumTime = 0;

    for (int i = 0; i < 5; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        saveService.execute(fileName);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        sumTime += elapsed.count();
        studentsRepository.clearData();
    }

    std::ofstream testsFile("../text-files/tests-results.txt", std::ios::app);
    if (testsFile.is_open()) {
        testsFile << "Average time taken for input: " << sumTime / 5 << " seconds\n";
        testsFile.close();
    } else {
        std::cerr << "Failed to open tests_results.txt for writing." << std::endl;
    }
}
