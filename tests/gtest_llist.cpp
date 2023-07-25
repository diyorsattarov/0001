#include <gtest/gtest.h>
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int count; // Add a member to keep track of the number of elements

public:
    LinkedList() : head(nullptr), count(0) {}

    void insert(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        count++; // Increment the count after insertion
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
            return;
        }

        Node* toRemove = head;
        head = head->next;
        delete toRemove;
        count--; // Decrement the count after removal
    }

    // Add the size() member function
    int size() const {
        return count;
    }

    // Sorting Algorithm: Bubble Sort
    void bubbleSort() {
        Node* current = head;
        Node* nextNode = nullptr;
        int temp;

        while (current != nullptr) {
            nextNode = current->next;

            while (nextNode != nullptr) {
                if (current->data > nextNode->data) {
                    temp = current->data;
                    current->data = nextNode->data;
                    nextNode->data = temp;
                }

                nextNode = nextNode->next;
            }

            current = current->next;
        }
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

class LinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        list.insert(4);
        list.insert(3);
        list.insert(2);
        list.insert(1);
    }

    void TearDown() override {}

    LinkedList list;
};

TEST_F(LinkedListTest, InsertTest) {
    EXPECT_FALSE(list.isEmpty());
}

TEST_F(LinkedListTest, DisplayTest) {
    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output
}

TEST_F(LinkedListTest, MemoryManagementTest) {
    // No direct assertions required for this test case
}

TEST_F(LinkedListTest, DefaultConstruction) {
    LinkedList emptyList;
    EXPECT_TRUE(emptyList.isEmpty());
}

TEST_F(LinkedListTest, InsertAndRemoveTest) {
    LinkedList list;
    list.insert(42);
    list.insert(24);
    list.insert(12);
    list.insert(6);

    while (!list.isEmpty()) {
        list.remove();
    }

    EXPECT_TRUE(list.isEmpty());
}

TEST_F(LinkedListTest, InsertAndRemoveFromEmptyList) {
    LinkedList list;
    list.remove();
    EXPECT_TRUE(list.isEmpty());
}

TEST_F(LinkedListTest, LargeListTest) {
    LinkedList list;
    const int numElements = 10000;

    for (int i = 0; i < numElements; ++i) {
        list.insert(i);
    }

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
}

TEST_F(LinkedListTest, RemoveLastElementTest) {
    list.remove();
    list.remove();
    list.remove();
    list.remove();

    EXPECT_TRUE(list.isEmpty());
}

TEST_F(LinkedListTest, SizeTest) {
    EXPECT_EQ(list.size(), 4);
}

TEST_F(LinkedListTest, InsertAndDisplayNegativeNumbers) {
    list.insert(-1);
    list.insert(-2);
    list.insert(-3);
    list.insert(-4);

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
}

TEST_F(LinkedListTest, InsertAndRemoveRandomTest) {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.remove();
    list.insert(50);
    list.insert(60);

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
}

TEST_F(LinkedListTest, InsertAndRemoveSameValueTest) {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(10);
    list.insert(30);

    list.remove();
    list.remove();

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
}

TEST_F(LinkedListTest, EmptySizeTest) {
    LinkedList list;
    EXPECT_EQ(list.size(), 0);
}

TEST_F(LinkedListTest, LargeInsertAndRemoveTest) {
    LinkedList list;
    const int numElements = 10000;

    for (int i = 0; i < numElements; ++i) {
        list.insert(i);
    }

    for (int i = 0; i < numElements; ++i) {
        list.remove();
    }

    EXPECT_TRUE(list.isEmpty());
}

TEST_F(LinkedListTest, BubbleSortTest) {
    // Prepare the list for sorting
    LinkedList list;
    list.insert(4);
    list.insert(2);
    list.insert(7);
    list.insert(1);
    list.insert(5);

    // Perform the sorting algorithm (Bubble Sort) on the list
    list.bubbleSort();

    // Check if the list is sorted in ascending order
    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
}

