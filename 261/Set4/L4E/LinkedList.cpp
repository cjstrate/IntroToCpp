#include "LinkedList.h"

LinkedList::LinkedList() {
    
    pHead = nullptr;
    pTail = nullptr;
    Size = 0;

}

LinkedList::~LinkedList() {
    
    while (pHead != nullptr){
        Node* pNew = pHead;
        pHead = (*pHead).pNext;
        delete pNew;
    }
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

    Size++;

    Node *pNew = mMakeNodeForValue(value);
    (*pNew).pNext = pHead;
    pHead = pNew;

}

void LinkedList::pushBack(int value){

    Size++;

    Node *pNew = mMakeNodeForValue(value);

    pTail = pHead;

    while ( (*pTail).pNext != nullptr ){
        pTail = (*pTail).pNext;
    }
    
    (*pTail).pNext = pNew;
    pTail = pNew;


}

int LinkedList::popFront(){

    Size--;

    Node *pNew = new Node;
    pNew = pHead;
    pHead = (*pHead).pNext;
    int value = (*pNew).value;
    delete pNew;
    return value;

}

LinkedList::LinkedList(const LinkedList &object){

    pHead = object.pHead;
    pTail = object.pTail;
    Size = object.Size;
    
    Node *pOld = object.pHead;
    Node *pNew = pHead;
    
    while(pOld != nullptr){
        (*pNew).pNext = (*pOld).pNext;
        pNew = (*pNew).pNext;
        pOld = (*pOld).pNext;
    } 

    delete pNew;
    delete pOld;

}

LinkedList LinkedList::copyAssignmentOperator(LinkedList object){
    
    LinkedList *lcopy = new LinkedList;
    *lcopy = object;
    object.~LinkedList();
    return *lcopy;

}

int LinkedList::at(int position){

    Node* pNew = pHead;
    for (int i = 0; i < position; i++){
        pNew = (*pNew).pNext;
    }

    if (pNew == nullptr){
        return -1;
    }


    int value = (*pNew).value;

    return value;

}