#include "abstract/generate-file-duration-test.h"
#include <chrono>
#include <fstream>
#include <iostream>

GenerateFileDurationTest::GenerateFileDurationTest(GenerateStudentsToFileUseCase& generateService)
    : generateService(generateService) {}

void GenerateFileDurationTest::testGenerateFileDuration(const std::string& fileSize) {
    double sumTime = 0;

    for (int i = 0; i < 5; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        generateService.execute(fileSize);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        sumTime += elapsed.count();
    }

    std::ofstream testsFile("../text-files/tests-results.txt", std::ios::app);
    if (testsFile.is_open()) {
        testsFile << "Average time taken for generating file with size " << fileSize << ": " << sumTime / 5 << " seconds\n";
        testsFile.close();
    } else {
        std::cerr << "Failed to open tests_results.txt for writing." << std::endl;
    }
}
