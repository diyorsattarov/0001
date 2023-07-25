#include <gtest/gtest.h>
#include <iostream>
#include <chrono>

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

    std::vector<int> getSortedElements() {
        std::vector<int> elements;
        Node* current = head;
        while (current != nullptr) {
            elements.push_back(current->data);
            current = current->next;
        }
        return elements;
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

TEST_F(LinkedListTest, DefaultConstruction) {
    LinkedList emptyList;
    EXPECT_TRUE(emptyList.isEmpty());
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
}

TEST_F(LinkedListTest, BubbleSortTest) {
    // Prepare the list for sorting
    LinkedList list;
    list.insert(4);
    list.insert(2);
    list.insert(7);
    list.insert(1);
    list.insert(5);

    list.bubbleSort();

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
}

TEST_F(LinkedListTest, SortAlreadySortedTest) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    list.bubbleSort();

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
    EXPECT_EQ(output, "1 2 3 4 5 \n");
}

TEST_F(LinkedListTest, SortWithDuplicateValuesTest) {
    LinkedList list;
    list.insert(3);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);

    list.bubbleSort();

    testing::internal::CaptureStdout();
    list.display();
    std::string output = testing::internal::GetCapturedStdout();
    // Add appropriate expectations to check the output and correctness of the elements
    EXPECT_EQ(output, "1 2 2 3 3 \n");
}

TEST_F(LinkedListTest, SortEmptyListTest) {
    LinkedList list;
    list.bubbleSort();
    EXPECT_TRUE(list.isEmpty());
}


TEST_F(LinkedListTest, PerformanceTest) {
    const int numElements = 10000; // You can adjust the number of elements as per your requirement

    LinkedList list;
    for (int i = numElements - 1; i >= 0; --i) {
        list.insert(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    list.bubbleSort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    // Check if the sorting meets your performance requirements (e.g., not taking too long)
    // You can set an appropriate threshold based on your performance requirements.
    double maxAllowedTimeInSeconds = 5.0;
    EXPECT_LT(duration.count(), maxAllowedTimeInSeconds);

    std::vector<int> sortedElements = list.getSortedElements();
    for (size_t i = 1; i < sortedElements.size(); ++i) {
        // Use EXPECT_LE to check if the current element is less than or equal to the previous element
        EXPECT_LE(sortedElements[i - 1], sortedElements[i]);
    }
}