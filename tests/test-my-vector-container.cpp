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