#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
    
    private:

        Node *pHead;
        Node *pTail;
        unsigned int Size;

        Node* mMakeNodeForValue(int value);

    public:

        LinkedList();

        int front();
        int back();
        unsigned int size();

        void pushFront(int value);
        void pushBack(int value);
        int popFront();

        ~LinkedList();

};

#endif