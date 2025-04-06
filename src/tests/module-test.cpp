#include "abstract/module-test.h"
#include <chrono>
#include <fstream>
#include <iostream>

ModuleTest::ModuleTest(
    SaveStudentsDataFromFileUseCase* saveService,
    SortStudentsUseCase* sortService,
    SortStudentsToBadAndGoodUseCase* sortToBadAndGoodService,
    PrintStudentsToFileUseCase* printGoodStudentsService,
    PrintStudentsToFileUseCase* printBadStudentsService
) : saveService(saveService), sortService(sortService), sortToBadAndGoodService(sortToBadAndGoodService), printGoodStudentsService(printGoodStudentsService), printBadStudentsService(printBadStudentsService) {}

void ModuleTest::testModule(const std::string& filename) {
    double wholeProgramSumTime = 0;
    double readStudentsFromFileTime = 0;
    double sortStudentsTime = 0;
    double sortStudentsToBadAndGoodTime = 0;
    double outputGoodAndBadStudentsTime = 0;

    for (int i = 0; i < 5; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        saveService->execute(filename);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        readStudentsFromFileTime += elapsed.count();
        wholeProgramSumTime += elapsed.count();

        start = std::chrono::high_resolution_clock::now();
        sortService->execute(false);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        sortStudentsTime += elapsed.count();
        wholeProgramSumTime += elapsed.count();

        start = std::chrono::high_resolution_clock::now();
        sortToBadAndGoodService->execute(false);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        sortStudentsToBadAndGoodTime += elapsed.count();
        wholeProgramSumTime += elapsed.count();

        start = std::chrono::high_resolution_clock::now();
        printGoodStudentsService->execute("good-students.txt");
        printBadStudentsService->execute("bad-students.txt");
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        outputGoodAndBadStudentsTime += elapsed.count();
        wholeProgramSumTime += elapsed.count();
    }

    std::ofstream testsFile("../text-files/tests-results.txt", std::ios::app);
    if (testsFile.is_open()) {
        testsFile << "Time to read students from file average: " << readStudentsFromFileTime / 5 << " seconds\n";
        testsFile << "Time to sort students average: " << sortStudentsTime / 5 << " seconds\n";
        testsFile << "Time to sort students to good and bad average: " << sortStudentsToBadAndGoodTime / 5 << " seconds\n";
        testsFile << "Time to output students to file average: " << outputGoodAndBadStudentsTime / 5 << " seconds\n";
        testsFile << "Time to run the whole program average: " << wholeProgramSumTime / 5 << " seconds\n";
        testsFile.close();
    } else {
        std::cerr << "Failed to open tests_results.txt for writing." << std::endl;
    }
}
