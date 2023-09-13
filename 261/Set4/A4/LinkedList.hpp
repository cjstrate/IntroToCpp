#include "Node.hpp"

template <typename T>
class LinkedList {
    
    private:

        Node<T> *pHead;
        Node<T> *pTail;
        unsigned int Size;

        T mMakeNodeForValue(const T value);

    public:

        LinkedList();

        T front();
        T back();
        unsigned int size();

        void pushFront(const T value);
        void pushBack(const T value);
        T popFront();
        void popBack();

        LinkedList(const LinkedList& object);
        T at(const int position);

        ~LinkedList();

};

template <typename T>
LinkedList<T>::LinkedList() {
    
    pHead = nullptr;
    pTail = nullptr;
    Size = 0;

}
template <typename T>
LinkedList<T>::~LinkedList() {
    
    while (pHead != nullptr){
        Node<T> *pNew = pHead;
        pHead = (*pHead).pNext;
        delete pNew;
    }
    delete pHead;
    delete pTail;

}

template <typename T>
T LinkedList<T>::mMakeNodeForValue(const T value) {
    
    Node<T> *makeNodeForValue = new Node<T>;
    (*makeNodeForValue).value = value;
    (*makeNodeForValue).pNext = nullptr;
    return makeNodeForValue;

}
template <typename T>
T LinkedList<T>::front(){

    if (pHead == nullptr){
        return T();
    }

    T value = (*pHead).value;
    return value;

}

template <typename T>
T LinkedList<T>::back(){

    if (pHead == nullptr){
        return T();
    }

    T value = (*pTail).value;
    return value;

}

template <typename T>
unsigned int LinkedList<T>::size(){
    return Size;
}

template <typename T>
void LinkedList<T>::pushFront(const T value) {

    Size++;

    Node<T> *pNew = new Node<T>;
    (*pNew).value = value;
    (*pNew).pNext = pHead;
    pHead = pNew;
    
    pTail = pHead;

    while((*pTail).pNext != nullptr){
        pTail = (*pTail).pNext;
    }

}
template <typename T>
void LinkedList<T>::pushBack(const T value){

    if (Size == 0){
        
        Size++;
        Node<T> *pNew = new Node<T>;
        (*pNew).value = value;
        (*pNew).pNext = pHead;
        pHead = pNew;
        
        pTail = pHead;

        while((*pTail).pNext != nullptr){
            pTail = (*pTail).pNext;
        }

    } else{

        Size++;

        Node<T> *pNew = new Node<T>;
        (*pNew).value = value;
        (*pNew).pNext = nullptr;

        pTail = pHead;

        while ( (*pTail).pNext != nullptr ){
            pTail = (*pTail).pNext;
        }
        
        (*pTail).pNext = pNew;
        pTail = pNew;
    
    }
}

template <typename T>
T LinkedList<T>::popFront(){

    Size--;

    Node<T> *pNew = new Node<T>;
    pNew = pHead;
    pHead = (*pHead).pNext;
    int value = (*pNew).value;
    delete pNew;
    return value;

}

template <typename T>
void LinkedList<T>::popBack(){
    Size--;

    delete pTail;

    pTail = pHead;
    while((*pTail).pNext != nullptr){
        pTail = (*pTail).pNext;
    }



}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &object){

    pHead = object.pHead;
    pTail = object.pTail;
    Size = object.Size;
    
    Node<T> *pOld = object.pHead;
    Node<T> *pNew = pHead;
    
    while(pOld != nullptr){
        (*pNew).pNext = (*pOld).pNext;
        pNew = (*pNew).pNext;
        pOld = (*pOld).pNext;
    } 

    delete pNew;
    delete pOld;

}

template <typename T>
T LinkedList<T>::at(const int position){

    Node<T> *pNew = pHead;
    for (int i = 0; i < position; i++){
        pNew = (*pNew).pNext;
    }

    if (pNew == nullptr){
        return T();
    }


    T value = (*pNew).value;

    return value;

}