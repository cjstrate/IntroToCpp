#include "LinkedList.h"

LinkedList::LinkedList() {
    
    pHead = nullptr;
    pTail = nullptr;
    Size = 0;

}

LinkedList::~LinkedList() {
    
    delete pHead;
    delete pTail;

}

Node* LinkedList::mMakeNodeForValue(int value) {
    
    Node* makeNodeForValue = new Node;
    (*makeNodeForValue).value = value;
    (*makeNodeForValue).pNext = nullptr;
    return makeNodeForValue;

}

int LinkedList::front(){

    if (pHead == nullptr){
        return -1;
    }

    int value = (*pHead).value;
    return value;

}

int LinkedList::back(){

    if (pHead == nullptr){
        return -1;
    }

    int value = (*pTail).value;
    return value;

}

unsigned int LinkedList::size(){

    return Size;
}

void LinkedList::pushFront(int value) {

    Node *pNew = mMakeNodeForValue(value);
    (*pNew).pNext = pHead;
    pHead = pNew;

}

void LinkedList::pushBack(int value){

    Node *pNew = mMakeNodeForValue(value);

    pTail = pHead;

    while ( (*pTail).pNext != nullptr ){
        pTail = (*pTail).pNext;
    }
    
    (*pTail).pNext = pNew;
    pTail = pNew;

}

int LinkedList::popFront(){

    Node *pNew = new Node;
    pNew = pHead;
    pHead = (*pHead).pNext;
    int value = (*pNew).value;
    delete pNew;
    return value;

}