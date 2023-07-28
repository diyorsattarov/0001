#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <chrono>
#include <gmock/gmock.h>


struct Node {
    int data;
    Node* next;
    virtual void setNext(Node* nextNode) 
    {
        next = nextNode;
    }
    virtual Node* getNext() const 
    {
        return next;
    }
};
#endif //NODE_H