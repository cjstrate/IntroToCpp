#include "Node.hpp"
#include <iostream>
using namespace std;

template <typename T>
class CircularlyDoublyLinkedList {

    private:

        Node<T> *pHead;
        Node<T> *pTail;
        int Size;

    public:
        Node<T> *pTurn;

        CircularlyDoublyLinkedList();
        CircularlyDoublyLinkedList(const CircularlyDoublyLinkedList& OBJECT);
        ~CircularlyDoublyLinkedList();
        CircularlyDoublyLinkedList& operator=(const CircularlyDoublyLinkedList& OTHER);

        T get(const int POS);
        void set(const int POS, const T VAL);
        void insert(const int POS, const T VAL);
        void remove(const int POS);
        int size();
        void print();
        void printReverse();
        void traverseCCW();
        void traverseCW();
        T getPlayer();
};

template <typename T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList() {

    pHead = nullptr;
    pTail = nullptr;
    pTurn = nullptr;
    Size = 0;

}

template <typename T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList(const CircularlyDoublyLinkedList& OBJECT) {

    pHead = OBJECT.pHead;
    pTail = OBJECT.pTail;
    Size = OBJECT.Size;

    Node<T> *pOriginal = OBJECT.pHead;
    Node<T> *pCopy = pHead;

    for (int i= 0; i < Size; i++) {
        pCopy -> pNext = pOriginal -> pNext;
        pCopy -> pPrev = pOriginal -> pPrev;
        pCopy = pCopy -> pNext;
        pOriginal = pOriginal -> pNext;
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    pTurn = pHead;

    delete pOriginal;
    delete pCopy;

}

template <typename T>
CircularlyDoublyLinkedList<T>::~CircularlyDoublyLinkedList() {
    while (!(pHead -> pNext = pTail)) {
        Node<T> *pTemp = new Node<T>;
        pTemp = pHead;
        pHead = pHead -> pNext;
        delete pTemp;
    }

    Size = 0;
    pHead = nullptr;
    pTail = nullptr;
    pTurn = nullptr;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::insert(const int POS, const T VAL) {

    // create node
    Node<T> *pNew = new Node<T>;
    pNew -> value = VAL;

    // Chech if pHead is null and then check posistion
    if (pHead == nullptr){
        pHead = pNew;
        pHead -> pNext = pTail;
        pTurn = pHead;

    } else if (POS <= 0){
        // check if pTail is null (there is only one number currently)
        if (pTail == nullptr){
            pTail = pHead;
            pTail -> pPrev = pHead;
            pTail -> pNext = pHead;
            pHead -> pPrev = pTail;
            pTurn = pHead;
        }
        
        pNew -> pNext = pHead;
        pHead -> pPrev = pNew;
        pHead = pNew;
        pHead -> pPrev = pTail;
        pTail -> pNext = pHead;
        pTurn = pHead;

    }
else {

        if (pTail == nullptr){
            pTail = pNew;
            pTail -> pPrev = pHead;
            pTail -> pNext = pHead;
            pHead -> pPrev = pTail;
            pTurn = pHead;
        }

        // iterate to POS
        Node<T> *pTemp = pHead;
        for (int i = 0; i < (POS - 1); i++){
            pTemp = pTemp -> pNext;
        }

        // insert the pNew into the POS
        pNew -> pNext = pTemp -> pNext;
        pNew -> pPrev = pTemp;
        pTemp -> pNext = pNew;
        pNew -> pNext -> pPrev = pNew;
        pHead -> pPrev = pTail;
        pTail -> pNext = pHead;
        pTurn = pHead;

    }
    pTurn = pHead;

    Size++;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::set(const int POS, const T VAL) {
    if (POS <= (Size - 1)){
        Node<T> *pTemp = pHead;

        for(int i = 0; i < POS; i++) {
            pTemp = pTemp -> pNext;
        }

        pTemp -> value = VAL;
    }
}

template <typename T>
void CircularlyDoublyLinkedList<T>::print() {
    Node<T> *pTemp = pHead;
   
    for (int i = 0; i < Size; i++){
        T Value = pTemp -> value;
        cout << Value << " ";
        pTemp = pTemp -> pNext;
    }
}

template <typename T>
void CircularlyDoublyLinkedList<T>::printReverse(){
    Node<T> *pLoc = pTail;

    cout << pLoc -> value << " ";
    while(pLoc != pHead){
        pLoc = pLoc -> pPrev;
        cout << pLoc -> value << " ";
    }
}

template <typename T>
int CircularlyDoublyLinkedList<T>::size() {
    return Size;
}

template <typename T>
T CircularlyDoublyLinkedList<T>::get(const int POS){
    if (POS > (Size - 1)){
        return T();
    }
    Node<T> *pTemp = pHead;
    for (int i = 0; i < POS; i++){
        pTemp = pTemp -> pNext;
    }

    return pTemp -> value;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::remove(const int POS){
    
    if (POS <= 0){
        Node<T> *pNew = pHead;
        pHead = pHead -> pNext;
        delete pNew;
        pNew = nullptr;
        pTail -> pNext = pHead;
        pHead -> pPrev = pTail;
    } else if (POS >= (Size - 1)){
        Node<T> *pNew = pTail;
        pTail = pTail -> pPrev;
        pTail -> pNext = pHead;
        pHead -> pPrev = pTail;
        delete pNew;
        pNew = nullptr;
    } else {
        Node<T> *pNew = pHead;
        for (int i = 0; i < POS; i++){
            pNew = pNew -> pNext;
        }
        pNew -> pPrev -> pNext = pNew -> pNext;
        pNew -> pNext -> pPrev = pNew -> pPrev;

        delete pNew;
        pNew = nullptr;
    }
    Size--;
}

template <typename T>
CircularlyDoublyLinkedList<T>& CircularlyDoublyLinkedList<T>::operator = (const CircularlyDoublyLinkedList<T>& OTHER){
    while (pHead != pTail) {
        Node<T> *pTemp = new Node<T>;
        pTemp = pHead;
        pHead = pHead -> pNext;
        delete pTemp;
    }
    Size = 0;
    pHead = nullptr;
    pTail = nullptr;

    pHead = OTHER.pHead;
    pTail = OTHER.pTail;
    Size = OTHER.Size;

    Node<T> *pOriginal = OTHER.pHead;
    Node<T> *pCopy = pHead;

    for (int i = 0; i < Size; i++) {
        pCopy -> pNext = pOriginal -> pNext;
        pCopy -> pPrev = pOriginal -> pPrev;
        pCopy = pCopy -> pNext;
        pOriginal = pOriginal -> pNext;
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    delete pOriginal;
    delete pCopy;

    return *this;

}

template <typename T>
void CircularlyDoublyLinkedList<T>::traverseCCW(){ 
    if (pTurn -> pPrev != nullptr){    
        pTurn = pTurn -> pPrev;
    }
}

template <typename T>
void CircularlyDoublyLinkedList<T>::traverseCW(){
    if (pTurn -> pNext != nullptr){
        pTurn = pTurn -> pNext;
    }
}


template <typename T>
T CircularlyDoublyLinkedList<T>::getPlayer(){
    if (pHead != nullptr){
        return pTurn -> value;
    }
    return T();
}