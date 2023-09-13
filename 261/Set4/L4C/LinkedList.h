#ifndef LINKEDLIST_H
#define LINKEDLIST_H

# include "Node.h"

class LinkedList {

public:
    
    Node *pHead;
    Node *pTail;
    int Size;

    Node* makeNodeForValue(int);
    void pushFront(int);
    void pushBack(int);
    int popFront();


};

#endif