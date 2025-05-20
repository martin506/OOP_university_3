#include <gtest/gtest.h>
#include "../src/models/abstract/student-model.h"

// Test default constructor
TEST(StudentTest, DefaultConstructor) {
    Student student;
    EXPECT_EQ(student.getName(), "Unknown");
    EXPECT_EQ(student.getSurname(), "Unknown");
    EXPECT_EQ(student.getExamGrade(), 8);
    EXPECT_EQ(student.getGrades().size(), 3);
    EXPECT_EQ(student.getGrades()[0], 8);
    EXPECT_EQ(student.getGrades()[1], 9);
    EXPECT_EQ(student.getGrades()[2], 10);
}

// Test parameterized constructor
TEST(StudentTest, ParameterizedConstructor) {
    Student student("martynas", "sima", 9, 8.5, 8.0);
    EXPECT_EQ(student.getName(), "martynas");
    EXPECT_EQ(student.getSurname(), "sima");
    EXPECT_EQ(student.getExamGrade(), 9);
    EXPECT_EQ(student.getFinalGradeWithAverage(), 8.5);
    EXPECT_EQ(student.getFinalGradeWithMedian(), 8.0);
}

// Test copy constructor
TEST(StudentTest, CopyConstructor) {
    Student original("martynas", "sima", 9, 8.5, 8.0);
    Student copy(original);
    EXPECT_EQ(copy.getName(), "martynas");
    EXPECT_EQ(copy.getSurname(), "sima");
    EXPECT_EQ(copy.getExamGrade(), 9);
    EXPECT_EQ(copy.getFinalGradeWithAverage(), 8.5);
    EXPECT_EQ(copy.getFinalGradeWithMedian(), 8.0);
}

// Test move constructor
TEST(StudentTest, MoveConstructor) {
    Student original("Martynas", "Sima", 9, 8.5, 8.0);
    Student moved(std::move(original));
    EXPECT_EQ(moved.getName(), "Martynas");
    EXPECT_EQ(moved.getSurname(), "Sima");
    EXPECT_EQ(moved.getExamGrade(), 9);
    EXPECT_EQ(moved.getFinalGradeWithAverage(), 8.5);
    EXPECT_EQ(moved.getFinalGradeWithMedian(), 8.0);
    EXPECT_EQ(original.getName(), "Unknown");
    EXPECT_EQ(original.getSurname(), "Unknown");
}

// Test calculateAverage
TEST(StudentTest, CalculateAverage) {
    Student student;
    std::cout << student.calculateAverage() << std::endl;
    EXPECT_EQ(student.calculateAverage(), 8.4); // Default grades: {8, 9, 10}, examGrade = 8
}

// Test calculateMedian
TEST(StudentTest, CalculateMedian) {
    Student student;
    EXPECT_NEAR(student.calculateMedian(), 8.4, 0.01); // Default grades: {8, 9, 10}, examGrade = 8
}

// Test isFinalGradeWithAveragePassing
TEST(StudentTest, IsFinalGradeWithAveragePassing) {
    Student student("Martynas", "Sima", 9, 5.0, 4.0);
    EXPECT_TRUE(student.isFinalGradeWithAveragePassing());
    EXPECT_FALSE(student.isFinalGradeWithMedianPassing());
}

// Test input and output operators
TEST(StudentTest, InputOutputOperators) {
    Student student;
    std::istringstream input("Martynas\nSima\n8 9 10 -1");
    input >> student;
    EXPECT_EQ(student.getName(), "Martynas");
    EXPECT_EQ(student.getSurname(), "Sima");
    EXPECT_EQ(student.getExamGrade(), 10);
    EXPECT_EQ(student.getGrades().size(), 2);
    EXPECT_EQ(student.getGrades()[0], 8);
    EXPECT_EQ(student.getGrades()[1], 9);

    std::ostringstream output;
    output << student;
    std::string expectedOutput = "Name: Martynas\n"
                                  "Surname: Sima\n"
                                  "Exam Grade: 10\n"
                                  "Final Grade (Avg): 9.4\n"
                                  "Final Grade (Med): 9.4\n"
                                  "Grades: 8 9 \n";
    EXPECT_EQ(output.str(), expectedOutput);
}