#include "Node.hpp"
#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {

    private:

        Node<T> *pHead;
        Node<T> *pTail;
        int Size;

    public:

        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList& OBJECT);
        ~DoublyLinkedList();
        DoublyLinkedList& operator=(const DoublyLinkedList& OTHER);

        T get(const int POS);
        void set(const int POS, const T VAL);
        void insert(const int POS, const T VAL);
        void remove(const int POS);
        int size();
        void print();
        void printReverse();

        void mergeSort(Node<T>** pList);
        void mergeSplit(Node<T>* pSource, Node<T>** pListFront, Node<T>** pListBack);
        Node<T>* merge(Node<T> *pLeftList, Node<T> *pRightList);

        void callMergeSort();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {

    pHead = nullptr;
    pTail = nullptr;
    Size = 0;

}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& OBJECT) {

    pHead = OBJECT.pHead;
    pTail = OBJECT.pTail;
    Size = OBJECT.Size;

    Node<T> *pOriginal = OBJECT.pHead;
    Node<T> *pCopy = pHead;

    while(pOriginal != nullptr) {
        pCopy -> pNext = pOriginal -> pNext;
        pCopy -> pPrev = pOriginal -> pPrev;
        pCopy = pCopy -> pNext;
        pOriginal = pOriginal -> pNext;
    }

    delete pOriginal;
    delete pCopy;

}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (!(pHead -> pNext = pTail)) {
        Node<T> *pTemp = new Node<T>;
        pTemp = pHead;
        pHead = pHead -> pNext;
        delete pTemp;
    }

    Size = 0;
    pHead = nullptr;
    pTail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::insert(const int POS, const T VAL) {

    // create node
    Node<T> *pNew = new Node<T>;
    pNew -> value = VAL;

    // Chech if pHead is null and then check posistion
    if (pHead == nullptr){
        pHead = pNew;
        pHead -> pNext = pTail;

    } else if (POS <= 0){
        // check if pTail is null (there is only one number currently)
        if (pTail == nullptr){
            pTail = pHead;
            pTail -> pPrev = pHead;
            pTail -> pNext = nullptr;
        }
       
        pNew -> pNext = pHead;
        pHead -> pPrev = pNew;
        pHead = pNew;

    } else if (POS >= (Size - 1)){
        // check if pTail is null (ther is only one number currently)
        if (pTail == nullptr){
            pTail = pNew;
            pTail -> pPrev = pHead;
            pTail -> pNext = nullptr;
        } else{
            pTail -> pNext = pNew;
            pNew -> pPrev = pTail;
            pTail = pNew;
            pTail -> pNext = nullptr;
        }
    }else {

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

    }

    Size++;
}

template <typename T>
void DoublyLinkedList<T>::set(const int POS, const T VAL) {
    if (POS <= (Size - 1)){
        Node<T> *pTemp = pHead;

        for(int i = 0; i < POS; i++) {
            pTemp = pTemp -> pNext;
        }

        pTemp -> value = VAL;
    }
}

template <typename T>
void DoublyLinkedList<T>::print() {
    Node<T> *pTemp = pHead;
   
    while (pTemp != nullptr){
        T Value = pTemp -> value;
        cout << Value << " ";
        pTemp = pTemp -> pNext;
    }
}

template <typename T>
void DoublyLinkedList<T>::printReverse(){
    Node<T> *pLoc = pTail;

    cout << pLoc -> value << " ";
    while(pLoc != pHead){
        pLoc = pLoc -> pPrev;
        cout << pLoc -> value << " ";
    }
}

template <typename T>
int DoublyLinkedList<T>::size() {
    return Size;
}

template <typename T>
T DoublyLinkedList<T>::get(const int POS){
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
void DoublyLinkedList<T>::remove(const int POS){
   
    if (POS <= 0){
        Node<T> *pNew = pHead;
        pHead = pHead -> pNext;
        delete pNew;
        pNew = nullptr;
    } else if (POS >= (Size - 1)){
        Node<T> *pNew = pTail;
        pTail = pTail -> pPrev;
        pTail -> pNext = nullptr;
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
DoublyLinkedList<T>& DoublyLinkedList<T>::operator = (const DoublyLinkedList<T>& OTHER){
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

    while(pOriginal != nullptr) {
        pCopy -> pNext = pOriginal -> pNext;
        pCopy -> pPrev = pOriginal -> pPrev;
        pCopy = pCopy -> pNext;
        pOriginal = pOriginal -> pNext;
    }

    delete pOriginal;
    delete pCopy;

    return *this;

}

template <typename T>
Node<T>* DoublyLinkedList<T>::merge(Node<T>* pListLeft, Node<T>* pListRight) {
    Node<T>* pResult = nullptr;

    // Test if the list is empty.
    if (pListLeft == nullptr) {
        return (pListRight);
    } else if (pListRight == nullptr) {
        return (pListLeft);
    }

    // Merge the partial lists into one larger list through recursion.

    // Test to see if it should be LEFT + RIGHT or RIGHT + LEFT
    if (pListLeft -> value <= pListRight -> value) {
        pResult = pListLeft;
        pResult -> pNext = merge(pListLeft -> pNext, pListRight);
    } else {
        pResult = pListRight;
        pResult -> pNext = merge(pListLeft, pListRight -> pNext);
    }

    return pResult;
}

template <typename T>
void DoublyLinkedList<T>::mergeSplit(Node<T>* pSource, Node<T>** pListFront, Node<T>** pListBack) {
    Node<T>* pFirst;
    Node<T>* pSecond;

    pFirst = pSource;
    pSecond = pSource -> pNext;

    // Increment pSecond twice for each increment of pFirst
    // So that when pSecond gets to the end, pFirst will be at middle
    while (pSecond != nullptr) {
        pSecond = pSecond -> pNext;
        if (pSecond != nullptr) {
            pFirst = pFirst -> pNext;
            pSecond = pSecond -> pNext;
        }
    }

    // Reassign values for recursive splitting
    *pListFront = pSource;
    *pListBack = pFirst -> pNext;
    pFirst -> pNext = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::mergeSort(Node<T>** pSource) {
    Node<T>* pListHead = *pSource;
    Node<T>* pLeft;
    Node<T>* pRight;

    // Check if list is empty
    if ((pListHead == nullptr) || (pListHead -> pNext == nullptr)) {
        return;
    }

    // Use the split function
    mergeSplit(pListHead, &pLeft, &pRight);

    // Sort the two split parts
    mergeSort(&pLeft);
    mergeSort(&pRight);

    // Reassign our head to the sorted linked list.
    *pSource = merge(pLeft, pRight);
}

template <typename T>
void DoublyLinkedList<T>::callMergeSort() {
    // Function to call mergeSort in main without needing pHead.
    mergeSort(&pHead);
}