#include <gtest/gtest.h>
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void remove() {
        if (head == nullptr) {
            // List is empty, nothing to remove
            return;
        }

        Node* toRemove = head;
        head = head->next;
        delete toRemove;
    }


    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Test fixture for the linked list tests
class LinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be executed before each test
        list.insert(4);
        list.insert(3);
        list.insert(2);
        list.insert(1);
    }

    void TearDown() override {
        // Code here will be executed after each test
    }

    LinkedList list;
};

// Test case to check insertion
TEST_F(LinkedListTest, InsertTest) 
{
    // Assert that the list is not empty after insertion
    EXPECT_FALSE(list.isEmpty());
    // Add more assertions to check the list's state after insertion
}

// Test case to check display
TEST_F(LinkedListTest, DisplayTest) 
{
    testing::internal::CaptureStdout(); // Redirect cout for testing
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output
    // For example, you can use EXPECT_EQ or EXPECT_NE to compare the output with the expected result
}

// Test case to check memory management (destructor)
TEST_F(LinkedListTest, MemoryManagementTest) 
{
    // No direct assertions required for this test case
    // The test will check for memory leaks or access violations when the destructor is called
}

// Test case to check if the list is empty after default construction
TEST_F(LinkedListTest, DefaultConstruction) 
{
    LinkedList emptyList;
    EXPECT_TRUE(emptyList.isEmpty());
}

// Test case to check if the list is empty after insertion and removal
TEST_F(LinkedListTest, InsertAndRemoveTest) 
{
    LinkedList list;
    list.insert(42);
    list.insert(24);
    list.insert(12);
    list.insert(6);

    // Remove elements one by one
    while (!list.isEmpty()) {
        list.display(); // Optional: Output for debugging
        list.remove();  // Assuming you have a remove() function to remove the first element
    }

    EXPECT_TRUE(list.isEmpty());
}

// Test case to check if the list remains empty after inserting and removing from an empty list
TEST_F(LinkedListTest, InsertAndRemoveFromEmptyList) 
{
    LinkedList list;
    list.remove(); // Assuming you have a remove() function to remove the first element
    EXPECT_TRUE(list.isEmpty());
}

// Test case to check large list insertion and display
TEST_F(LinkedListTest, LargeListTest) 
{
    LinkedList list;
    const int numElements = 10000;

    for (int i = 0; i < numElements; ++i) {
        list.insert(i);
    }

    testing::internal::CaptureStdout(); // Redirect cout for testing
    list.display();
    std::string output = testing::internal::GetCapturedStdout();

    // Add appropriate expectations to check the output and correctness of the elements
}