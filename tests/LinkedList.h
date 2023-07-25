#include <vector>

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