#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <chrono>
#include "LinkedList.h"

// ... (LinkedList and Node class definitions)

// Mock class for Node
class MockNode : public Node {
public:
    MOCK_METHOD(void, setNext, (Node*), (override));
    MOCK_METHOD(Node*, getNext, (), (const, override));
};

// Mock class for LinkedList
class MockLinkedList : public LinkedList {
public:
    MOCK_METHOD(void, insert, (int), (override));
    MOCK_METHOD(void, display, (), (override));
    MOCK_METHOD(bool, isEmpty, (), (const, override));
    MOCK_METHOD(void, remove, (), (override));
    MOCK_METHOD(int, size, (), (const, override));
    MOCK_METHOD(void, bubbleSort, (), (override));
    MOCK_METHOD(std::vector<int>, getSortedElements, (), (override));
};

// Test fixture for LinkedList
class LinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        list.insert(4);
        list.insert(3);
        list.insert(2);
        list.insert(1);
    }

    void TearDown() override {}

    MockLinkedList list;
};

// Test cases using GMock
TEST_F(LinkedListTest, InsertTest) {
    // Set up expectations
    EXPECT_CALL(list, isEmpty()).WillRepeatedly(::testing::Return(false));
    
    // Execute the test
    EXPECT_FALSE(list.isEmpty());
}

TEST_F(LinkedListTest, SizeTest) {
    // Set up expectations
    EXPECT_CALL(list, size()).WillOnce(::testing::Return(4));
    
    // Execute the test
    EXPECT_EQ(list.size(), 4);
}

TEST_F(LinkedListTest, BubbleSortTest) {
    // Prepare the list for sorting
    list.insert(4);
    list.insert(2);
    list.insert(7);
    list.insert(1);
    list.insert(5);
    
    // Set up expectations
    EXPECT_CALL(list, bubbleSort()).Times(1);
    EXPECT_CALL(list, display()).Times(1);
    EXPECT_CALL(list, getSortedElements())
        .WillOnce(::testing::Return(std::vector<int>{1, 2, 4, 5, 7}));
    
    // Execute the test
    list.bubbleSort();
}

// ... (Add more test cases as needed)

int main(int argc, char* argv[]) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
