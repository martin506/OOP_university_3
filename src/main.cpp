#include "abstract/students-data-sort-runner.h"

int main() {
    StudentsDataSortRunner runner;
    //runner.run();

     //Default constructor testing
     Student studentTesting;
     std::cout<<std::setw(45)<<std::left<<"Default constructor: "<<studentTesting;
 
     //Rule of 5 testing
     Student studentas("Martynas", "Simas", 8, 7, 6);
     std::cout<<std::setw(45)<<std::left<<"Constructor: "<<studentas;
     Student studentasTest1 {studentas};
     std::cout<<std::setw(45)<<std::left<<"Copy constructor: "<<studentasTest1;
     Student studentasTest2;
     studentasTest2 = studentasTest1;
     std::cout<<std::setw(45)<<std::left<<"Copy assignment: "<<studentasTest2;
     Student studentasTest3 {std::move(studentasTest2)};
     std::cout<<std::setw(45)<<std::left<<"Move constructor: "<<studentasTest3;
     std::cout<<std::setw(45)<<std::left<<"Moved Constructor: "<<studentasTest2;
     Student studentasTest4 = std::move(studentasTest3);
     std::cout<<std::setw(45)<<std::left<<"Moved assignment: "<<studentasTest4;
     std::cout<<std::setw(45)<<std::left<<"Moved with assignment (should be deleted): "<<studentasTest3;
}
