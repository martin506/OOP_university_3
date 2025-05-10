#include "student-model.h"

Student::Student()
    : name("name"), surname("surname"), examGrade(8), finalGradeWithAverage(0), finalGradeWithMedian(0) {}

Student::~Student() {
    name = "";
    surname = "";
    examGrade = 0;
    finalGradeWithAverage = 0;
    finalGradeWithMedian = 0;
    grades.clear();
}

Student::Student(const std::string& name, const std::string& surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian)
    : name(name), surname(surname), examGrade(examGrade), finalGradeWithAverage(finalGradeWithAverage), finalGradeWithMedian(finalGradeWithMedian) {}

// Copy Constructor
Student::Student(const Student& other)
    : name(other.name), surname(other.surname), examGrade(other.examGrade),
      finalGradeWithAverage(other.finalGradeWithAverage), finalGradeWithMedian(other.finalGradeWithMedian),
      grades(other.grades) {}

// Copy Assignment Operator
Student& Student::operator=(const Student& other) {
    if (this == &other) return *this;
    name = other.name;
    surname = other.surname;
    examGrade = other.examGrade;
    finalGradeWithAverage = other.finalGradeWithAverage;
    finalGradeWithMedian = other.finalGradeWithMedian;
    grades = other.grades;
    return *this;
}

// Move Constructor
Student::Student(Student&& other) noexcept
    : name(std::move(other.name)), surname(std::move(other.surname)), examGrade(other.examGrade),
      finalGradeWithAverage(other.finalGradeWithAverage), finalGradeWithMedian(other.finalGradeWithMedian),
      grades(std::move(other.grades)) {
    other.~Student();
}

// Move Assignment Operator
Student& Student::operator=(Student&& other) noexcept {
    if (this == &other) return *this;
    name = std::move(other.name);
    surname = std::move(other.surname);
    examGrade = other.examGrade;
    finalGradeWithAverage = other.finalGradeWithAverage;
    finalGradeWithMedian = other.finalGradeWithMedian;
    grades = std::move(other.grades);

    other.~Student();
    return *this;
}

// Output Operator
std::ostream& operator<<(std::ostream& out, const Student& stud) {
    out << std::setw(15) << std::left << "Name: " << stud.name << "\n"
        << std::setw(15) << std::left << "Surname: " << stud.surname << "\n"
        << std::setw(15) << std::left << "Exam Grade: " << stud.examGrade << "\n"
        << std::setw(15) << std::left << "Final Grade (Avg): " << stud.finalGradeWithAverage << "\n"
        << std::setw(15) << std::left << "Final Grade (Med): " << stud.finalGradeWithMedian << "\n"
        << std::setw(15) << std::left << "Grades: ";
    for (const auto& grade : stud.grades) {
        out << grade << " ";
    }
    out << "\n";
    return out;
}

// Input Operator
std::istream& operator>>(std::istream& in, Student& stud) {
    std::cout << "Enter Name: ";
    in >> stud.name;
    std::cout << "Enter Surname: ";
    in >> stud.surname;

    stud.grades.clear();
    std::cout << "Enter Grades (end with -1, last grade will be treated as Exam Grade): ";
    int grade;
    while (in >> grade && grade != -1) {
        stud.grades.push_back(grade);
    }

    if (!stud.grades.empty()) {
        stud.examGrade = stud.grades.back();
        stud.grades.pop_back();
    } else {
        stud.examGrade = 0;
    }

    stud.finalGradeWithAverage = stud.calculateAverage();
    stud.finalGradeWithMedian = stud.calculateMedian();

    return in;
}

void Student::addGrade(int grade) {
    grades.push_back(grade);
}

void Student::removeLastGrade() {
    if (!grades.empty()) {
        grades.pop_back();
    }
}

double Student::calculateAverage() const {
    if (grades.empty()) return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0);
    return (sum / grades.size()) * 0.4 + 0.6 * examGrade;
}

double Student::calculateMedian() const {
    if (grades.empty()) return 0.0;
    std::vector<int> sortedGrades = grades;
    std::sort(sortedGrades.begin(), sortedGrades.end());
    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return ((sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0) * 0.4 + 0.6 * examGrade;
    } else {
        return sortedGrades[size / 2] * 0.4 + 0.6 * examGrade;
    }
}

bool Student::isFinalGradeWithAveragePassing() const {
    return finalGradeWithAverage >= 5;
}

bool Student::isFinalGradeWithMedianPassing() const {
    return finalGradeWithMedian >= 5;
}
