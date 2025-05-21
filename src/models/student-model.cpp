#include "abstract/student-model.h"

Student::Student()
    : examGrade(8), finalGradeWithAverage(0), finalGradeWithMedian(0)
{
    setName("Unknown");
    setSurname("Unknown");
    grades = {8, 9, 10};
}

Student::~Student() {
    setName("Unknown");
    setSurname("Unknown");
    examGrade = 0;
    finalGradeWithAverage = 0;
    finalGradeWithMedian = 0;
    grades.clear();
};

Student::Student(const std::string &name, const std::string &surname, int examGrade, double finalGradeWithAverage, double finalGradeWithMedian)
    : examGrade(examGrade), finalGradeWithAverage(finalGradeWithAverage), finalGradeWithMedian(finalGradeWithMedian)
{
    setName(name);
    setSurname(surname);
    grades = {8, 9, 10};
}

// Copy Constructor
Student::Student(const Student &other)
    : examGrade(other.examGrade), finalGradeWithAverage(other.finalGradeWithAverage),
      finalGradeWithMedian(other.finalGradeWithMedian), grades(other.grades)
{
    setName(other.getName());
    setSurname(other.getSurname());
}

// Copy Assignment Operator
Student &Student::operator=(const Student &other)
{
    if (this == &other)
        return *this; 
    setName(other.getName());
    setSurname(other.getSurname());
    examGrade = other.examGrade;
    finalGradeWithAverage = other.finalGradeWithAverage;
    finalGradeWithMedian = other.finalGradeWithMedian;
    grades = other.grades;
    return *this;
}

// Move Constructor
Student::Student(Student &&other) noexcept
    : examGrade(other.examGrade), finalGradeWithAverage(other.finalGradeWithAverage),
      finalGradeWithMedian(other.finalGradeWithMedian), grades(std::move(other.grades))
{
    setName(other.getName());
    setSurname(other.getSurname());
    other.setName("Unknown");
    other.setSurname("Unknown");
    other.examGrade = 0;    
    other.finalGradeWithAverage = 0;
    other.finalGradeWithMedian = 0;
}

// Move Assignment Operator
Student &Student::operator=(Student &&other) noexcept
{
    if (this == &other)
        return *this; // Handle self-assignment
    setName(other.getName());
    setSurname(other.getSurname());
    examGrade = other.examGrade;
    finalGradeWithAverage = other.finalGradeWithAverage;
    finalGradeWithMedian = other.finalGradeWithMedian;
    grades = std::move(other.grades);
    
    other.setName("Unknown");
    other.setSurname("Unknown");
    other.examGrade = 0;
    other.finalGradeWithAverage = 0;
    other.finalGradeWithMedian = 0;
    return *this;
}

void Student::addGrade(int grade)
{
    grades.push_back(grade);
}

void Student::removeLastGrade()
{
    if (!grades.empty())
    {
        grades.pop_back();
    }
}

double Student::calculateAverage() const
{
    if (grades.empty())
        return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0);
    double average = sum / grades.size();
    return 0.4 * average + 0.6 * examGrade;
}

double Student::calculateMedian() const
{
    if (grades.empty())
        return 0.0;
    std::vector<int> sortedGrades = grades;
    std::sort(sortedGrades.begin(), sortedGrades.end());
    size_t size = sortedGrades.size();
    double median;
    if (size % 2 == 0)
    {
        median = (sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0;
    }
    else
    {
        median = sortedGrades[size / 2];
    }
    return 0.4 * median + 0.6 * examGrade;
}

bool Student::isFinalGradeWithAveragePassing() const
{
    return finalGradeWithAverage >= 5;
}

bool Student::isFinalGradeWithMedianPassing() const
{
    return finalGradeWithMedian >= 5;
}

// Output Operator
std::ostream &operator<<(std::ostream &out, const Student &stud)
{
    out << "Name: " << stud.getName() << "\n"
        << "Surname: " << stud.getSurname() << "\n"
        << "Exam Grade: " << stud.examGrade << "\n"
        << "Final Grade (Avg): " << stud.finalGradeWithAverage << "\n"
        << "Final Grade (Med): " << stud.finalGradeWithMedian << "\n"
        << "Grades: ";
    for (const auto &grade : stud.grades)
    {
        out << grade << " ";
    }
    out << "\n";
    return out;
}

// Input Operator
std::istream &operator>>(std::istream &in, Student &stud)
{
    std::string name, surname;
    in >> name;
    stud.setName(name);
    in >> surname;
    stud.setSurname(surname);

    stud.grades.clear();
    int grade;
    while (in >> grade && grade != -1)
    {
        stud.grades.push_back(grade);
    }

    if (!stud.grades.empty())
    {
        stud.examGrade = stud.grades.back();
        stud.grades.pop_back();
    }
    else
    {
        stud.examGrade = 0;
    }

    stud.finalGradeWithAverage = stud.calculateAverage();
    stud.finalGradeWithMedian = stud.calculateMedian();

    return in;
}