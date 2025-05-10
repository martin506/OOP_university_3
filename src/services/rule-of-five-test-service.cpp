#include "abstract/rule-of-five-test-service.h"

RuleOfFiveTestService::RuleOfFiveTestService() { }

void RuleOfFiveTestService::execute(bool needsParameter) {
    try {
        Student student1 = Student();
        std::cout << "Default constructor: \n" << student1 << "\n";

        Student student2 =  Student("Martynas", "Simas", 8, 7, 6);
        std::cout << "Constructor: " << student2 << "\n";
        Student student3{student2};
        std::cout << "Copy constructor: \n" << student3 << "\n";
        Student student4;
        student4 = student3;
        std::cout << "Copy assignment: \n" << student4 << "\n";
        Student student5{std::move(student4)};
        std::cout <<"Move constructor: \n" << student5 << "\n";
        std::cout << "Moved Constructor: \n" << student4 << "\n";
        Student student6 = std::move(student5);
        std::cout << "Moved assignment: \n" << student6 << "\n";
        std::cout << "Moved with assignment (should be deleted): \n" << student5 << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}