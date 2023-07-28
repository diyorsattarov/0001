#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "linkedlist.h"

class MockLinkedList : public LinkedList 
{
public:
    
    MOCK_METHOD(void, remove, (), (override));
    MOCK_METHOD(bool, isEmpty, (), (const, override));

    MOCK_METHOD(std::string, stringList, (), (const, override));
    MOCK_METHOD(void, clear, (), (override));
    MOCK_METHOD(void, insert, (int), (override));
    MOCK_METHOD(int, getSize, (), (const, override));
    MOCK_METHOD(Node*, getHead, (), (const, override));
};

class LinkedListTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        mockList = new MockLinkedList;
    }

    void TearDown() override 
    {
        delete mockList;
    }

    MockLinkedList* mockList;
};

TEST_F(LinkedListTest, GetHeadEmptyList) 
{
    EXPECT_CALL(*mockList, getHead()).WillOnce(::testing::Return(static_cast<Node*>(nullptr)));

    Node* head = mockList->getHead();
    ASSERT_EQ(head, nullptr);
}

TEST_F(LinkedListTest, GetHeadNonEmptyList) 
{
    Node* mockHead = new Node;
    mockHead->data = 42;
    EXPECT_CALL(*mockList, getHead()).WillOnce(::testing::Return(mockHead));

    Node* head = mockList->getHead();
    ASSERT_EQ(head->data, 42);
}

TEST_F(LinkedListTest, GetHeadAfterInsertion) 
{
    int testData = 42;
    EXPECT_CALL(*mockList, insert(testData)).Times(1);

    Node* mockHead = new Node;
    mockHead->data = testData;
    EXPECT_CALL(*mockList, getHead())
        .WillOnce(::testing::Return(static_cast<Node*>(nullptr)))
        .WillOnce(::testing::Return(mockHead));

    mockList->insert(testData);

    Node* headBeforeInsertion = mockList->getHead();
    ASSERT_EQ(headBeforeInsertion, nullptr);

    Node* headAfterInsertion = mockList->getHead();
    ASSERT_EQ(headAfterInsertion->data, testData);
}

TEST_F(LinkedListTest, GetHeadMultipleInsertions) 
{
    int testData1 = 42;
    int testData2 = 77;
    EXPECT_CALL(*mockList, insert(testData1)).Times(1);
    EXPECT_CALL(*mockList, insert(testData2)).Times(1);

    Node* mockHead1 = new Node;
    mockHead1->data = testData1;
    Node* mockHead2 = new Node;
    mockHead2->data = testData2;
    EXPECT_CALL(*mockList, getHead())
        .WillOnce(::testing::Return(mockHead1))  
        .WillOnce(::testing::Return(mockHead2)); 

    mockList->insert(testData1);
    mockList->insert(testData2);

    Node* headAfterFirstInsertion = mockList->getHead();
    ASSERT_EQ(headAfterFirstInsertion->data, testData1);

    Node* headAfterSecondInsertion = mockList->getHead();
    ASSERT_EQ(headAfterSecondInsertion->data, testData2);
}

TEST_F(LinkedListTest, GetSizeEmptyList)
{
    EXPECT_CALL(*mockList, getSize()).WillOnce(::testing::Return(0));

    int size = mockList->getSize();
    ASSERT_EQ(size, 0);
}

TEST_F(LinkedListTest, GetSizeAfterInsertion)
{
    int testData = 42;
    EXPECT_CALL(*mockList, insert(testData)).Times(1);
    EXPECT_CALL(*mockList, getSize()).WillOnce(::testing::Return(1));

    mockList->insert(testData);
    int size = mockList->getSize();
    ASSERT_EQ(size, 1);
}

TEST_F(LinkedListTest, GetSizeAfterMultipleInsertions)
{
    int testData1 = 42;
    int testData2 = 77;

    EXPECT_CALL(*mockList, insert(testData1)).Times(1);
    EXPECT_CALL(*mockList, insert(testData2)).Times(1);
    EXPECT_CALL(*mockList, getSize()).WillOnce(::testing::Return(2));

    mockList->insert(testData1);
    mockList->insert(testData2);
    int size = mockList->getSize();
    ASSERT_EQ(size, 2);
}

TEST_F(LinkedListTest, GetSizeAfterInsertionAndRemoval)
{
    int testData1 = 42;

    EXPECT_CALL(*mockList, insert(testData1)).Times(1);
    EXPECT_CALL(*mockList, remove()).Times(1);
    EXPECT_CALL(*mockList, getSize()).WillOnce(::testing::Return(0));

    mockList->insert(testData1);
    mockList->remove();
    int size = mockList->getSize();
    ASSERT_EQ(size, 0);
}

TEST_F(LinkedListTest, GetSizeAfterMultipleInsertionsAndRemovals)
{
    int testData1 = 42;
    int testData2 = 77;

    EXPECT_CALL(*mockList, insert(testData1)).Times(1);
    EXPECT_CALL(*mockList, insert(testData2)).Times(1);
    EXPECT_CALL(*mockList, remove()).Times(1);
    EXPECT_CALL(*mockList, getSize()).WillOnce(::testing::Return(1));

    mockList->insert(testData1);
    mockList->insert(testData2);
    mockList->remove();
    int size = mockList->getSize();
    ASSERT_EQ(size, 1);
}

TEST_F(LinkedListTest, GetSizeAfterClearingList)
{
    int testData1 = 42;
    int testData2 = 77;

    EXPECT_CALL(*mockList, insert(testData1)).Times(1);
    EXPECT_CALL(*mockList, insert(testData2)).Times(1);
    EXPECT_CALL(*mockList, clear()).Times(1);

    mockList->insert(testData1);
    mockList->insert(testData2);
    mockList->clear();

    int size = mockList->getSize();
    ASSERT_EQ(size, 0);
}

TEST_F(LinkedListTest, StringListTest)
{
    int testData1 = 42;
    int testData2 = 77;

    std::string expectedOutput = std::to_string(testData2) + " " + std::to_string(testData1) + " ";

    EXPECT_CALL(*mockList, stringList()).WillOnce(::testing::Return(expectedOutput));

    mockList->insert(testData1);
    mockList->insert(testData2);

    std::string output = mockList->stringList();

    ASSERT_EQ(output, expectedOutput);
}



TEST_F(LinkedListTest, RemoveTest)
{
    EXPECT_CALL(*mockList, remove()).Times(1);
    mockList->remove();
}

TEST_F(LinkedListTest, IsEmptyTest)
{
    EXPECT_CALL(*mockList, isEmpty()).WillOnce(::testing::Return(true));

    bool empty = mockList->isEmpty();
    ASSERT_TRUE(empty);
}

TEST_F(LinkedListTest, IsNotEmptyTest)
{
    EXPECT_CALL(*mockList, insert(::testing::_)).Times(1);
    EXPECT_CALL(*mockList, isEmpty()).WillOnce(::testing::Return(false));

    mockList->insert(42);
    bool empty = mockList->isEmpty();
    ASSERT_FALSE(empty);
}

TEST_F(LinkedListTest, ClearTest)
{
    int testData1 = 42;
    int testData2 = 77;

    EXPECT_CALL(*mockList, insert(testData1)).Times(1);
    EXPECT_CALL(*mockList, insert(testData2)).Times(1);
    EXPECT_CALL(*mockList, getSize()).WillOnce(::testing::Return(0));
    EXPECT_CALL(*mockList, clear()).Times(1);

    mockList->insert(testData1);
    mockList->insert(testData2);
    mockList->clear();

    int size = mockList->getSize();
    ASSERT_EQ(size, 0);
}
