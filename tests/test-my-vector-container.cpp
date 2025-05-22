#include <gtest/gtest.h>
#include "../src/containers/abstract/my-vector-container.h"

// Test default constructor
TEST(MyVectorTest, DefaultConstructor) {
    MyVector<int> vec;
    EXPECT_EQ(vec.get_size(), 0);
    EXPECT_EQ(vec.get_capacity(), 0);
    EXPECT_TRUE(vec.empty());
}

// Test push_back
TEST(MyVectorTest, PushBack) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.get_size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Test pop_back
TEST(MyVectorTest, PopBack) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.pop_back();

    EXPECT_EQ(vec.get_size(), 1);
    EXPECT_EQ(vec[0], 1);

    vec.pop_back();
    EXPECT_TRUE(vec.empty());
}

// Test insert
TEST(MyVectorTest, Insert) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.insert(1, 2);

    EXPECT_EQ(vec.get_size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Test erase
TEST(MyVectorTest, Erase) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.erase(1);

    EXPECT_EQ(vec.get_size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
}

// Test clear
TEST(MyVectorTest, Clear) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.clear();

    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.get_size(), 0);
}

// Test at (bounds-checked access)
TEST(MyVectorTest, At) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 2);

    EXPECT_THROW(vec.at(2), std::out_of_range);
}

// Test reserve and capacity
TEST(MyVectorTest, ReserveAndCapacity) {
    MyVector<int> vec;
    vec.reserve(10);

    EXPECT_EQ(vec.get_capacity(), 10);
    EXPECT_EQ(vec.get_size(), 0);

    vec.push_back(1);
    EXPECT_EQ(vec.get_capacity(), 10);
    EXPECT_EQ(vec.get_size(), 1);
}

// Test sort
TEST(MyVectorTest, Sort) {
    MyVector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.sort();

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Test reverse
TEST(MyVectorTest, Reverse) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.reverse();

    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 1);
}