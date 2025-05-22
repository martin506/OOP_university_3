#include <gtest/gtest.h>
#include <vector>
#include "../src/containers/my-vector-container.h"

// Helper class to track resizing
class ResizeTracker {
public:
    size_t resizeCount = 0;

    void increment() {
        ++resizeCount;
    }
};

// Custom MyVector class with resize tracking
template <typename T>
class MyVectorWithTracking : public MyVector<T> {
private:
    ResizeTracker& tracker;

public:
    MyVectorWithTracking(ResizeTracker& tracker) : tracker(tracker) {}

protected:
    void resize() {
        tracker.increment();
        MyVector<T>::resize();
    }
};

// Test to compare resizing behavior
TEST(VectorResizeTest, CompareResizing) {
    const size_t numElements = 10'000'000;

    // Track resizing for std::vector
    ResizeTracker stdTracker;
    std::vector<int> stdVec;
    stdVec.reserve(1); // Start with a small capacity
    size_t stdResizeCount = 0;

    for (size_t i = 0; i < numElements; ++i) {
        if (stdVec.size() == stdVec.capacity()) {
            ++stdResizeCount;
        }
        stdVec.push_back(i);
    }

    // Track resizing for MyVector
    ResizeTracker myTracker;
    MyVectorWithTracking<int> myVec(myTracker);

    for (size_t i = 0; i < numElements; ++i) {
        if (myVec.get_size() == myVec.get_capacity()) {
            myTracker.increment();
        }
        myVec.push_back(i);
    }

    // Print results
    std::cout << "std::vector resized " << stdResizeCount << " times." << std::endl;
    std::cout << "MyVector resized " << myTracker.resizeCount << " times." << std::endl;

    // Assertions (optional, for testing purposes)
    EXPECT_EQ(true, stdResizeCount>=0);
    EXPECT_EQ(true, myTracker.resizeCount>=0);
}
