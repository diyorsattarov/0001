#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>
#include <iostream>
#include <chrono>
#include "node.h"

class LinkedList {
private:
    Node* head;
    int count; 

public:
    LinkedList() : head(nullptr), count(0) {}

    virtual Node* getHead() const 
    {
        return head;
    }

    virtual int getSize() const 
    {
        return count;
    }

    virtual void insert(int data) 
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        count++; 
    }

    virtual std::string stringList() const
    {
        std::ostringstream oss;
        Node* current = head;
        while (current != nullptr) 
        {
            oss << current->data << " ";
            current = current->next;
        }
        return oss.str();
    }

    virtual bool isEmpty() const 
    {
        return head == nullptr;
    }
    
    virtual void remove() 
    {
        if (head == nullptr) {
            return;
        }

        Node* toRemove = head;
        head = head->next;
        delete toRemove;
        count--; // Decrement the count after removal
    }
    //virtual void bubbleSort() {}
    //virtual std::vector<int> getSortedElements() {}

    virtual void clear() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        count = 0;
    }
    
    ~LinkedList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

#endif // LINKED_LIST_H
