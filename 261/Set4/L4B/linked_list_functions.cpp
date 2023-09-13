#include "linked_list_functions.h"

Node* linked_list_make_node(const int VALUE) {
    Node *pHead = new Node;
    (*pHead).value = VALUE;
    (*pHead).pNext = nullptr;
    return pHead;
}

int linked_list_get_size(Node* pHead) {
    int nums = 0;

    Node *pCurrent = pHead;
    while (pCurrent != nullptr){
        nums++;
        pCurrent = (*pCurrent).pNext;
    }

    return nums;
}

Node* linked_list_add_value_to_front(Node* pHead, const int VALUE) {
    
    Node *pNew = new Node;
    (*pNew).value = VALUE;
    (*pNew).pNext = pHead;
    pHead = pNew;

    return pHead;
}

int linked_list_get_value_at_position(Node* pHead, const int POS) {
    
    if (POS >= linked_list_get_size(pHead) || POS < 0){
        return -1;
    }

    int index = 0;
    Node *pCurrent = pHead;
    while (index < POS && pCurrent != nullptr){
        index++;
        pCurrent = (*pCurrent).pNext;
    }
    return (*pCurrent).value;

}

int linked_list_min(Node* pHead) {
   
   int min;
   Node *pCurrent = pHead;
   if (pCurrent == nullptr){
       return -1;
   }
   min = (*pCurrent).value;
   if (pCurrent == nullptr){
       return -1;
   }

   while (pCurrent != nullptr){
       if ((*pCurrent).value < min){
           min = (*pCurrent).value;
       }
       pCurrent = (*pCurrent).pNext;
   }

    return min;
}

int linked_list_max(Node* pHead) {

   int max;
   Node *pCurrent = pHead;
   if (pCurrent == nullptr){
       return -1;
   }
   max = (*pCurrent).value;
   if (pCurrent == nullptr){
       return -1;
   }

   while (pCurrent != nullptr){
       if ((*pCurrent).value > max){
           max = (*pCurrent).value;
       }
       pCurrent = (*pCurrent).pNext;
   }

    return max;
}

int linked_list_find(Node* pHead, const int TARGET) {
    
    Node *pCurrent = pHead;
    if (pCurrent == nullptr){
        return -1;
    }

    int index = 0;
    while (pCurrent != nullptr){
        if ((*pCurrent).value == TARGET){
            return index;
        }
        pCurrent = (*pCurrent).pNext;
        index++;
    }
    return -1;

}

Node* linked_list_remove_node_from_front(Node* pHead) {
    
    if (pHead == nullptr){
        return pHead;
    }

    Node *pRemove = new Node;
    pRemove = pHead;
    pHead = (*pHead).pNext;
    delete pRemove;

    return pHead;
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE) {
    
    if (linked_list_get_size(pHead) <= POS){
        return pHead;
    }

    int index = 0;
    Node *pCurrent = pHead;
    while (pCurrent != nullptr){
        if (index == POS){
            (*pCurrent).value = VALUE;
        }
        pCurrent = (*pCurrent).pNext;
        index++;
    }
    return pHead;
}