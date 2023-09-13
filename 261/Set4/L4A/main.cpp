# include <iostream>
using namespace std;

struct Node {
    int value;
    Node *pNext;
};

int main(){
    
    int* pArray = new int[3];

    for (int i = 1; i <= 3; i++){
        cout << "Enter element " << i << ": ";
        cin >> pArray[i - 1];
    }

    cout << "Array in order:" << endl;
    for (int i = 0; i < 3; i++){
        cout << pArray[i] << " ";
    }
    cout << endl;

    cout << "Array in reverse order:" << endl;
    for (int i = 2; i >= 0; i--){
        cout << pArray[i] << " ";
    }
    cout << endl;

    Node *pHead = new Node;
    Node *pSecond = new Node;
    Node *pTail = new Node;

    int user_in_1;
    int user_in_2;
    int user_in_3;

    cout << "Enter element 1: ";
    cin >> user_in_1;
    cout << "Enter element 2: ";
    cin >> user_in_2;
    cout << "Enter element 3: ";
    cin >> user_in_3;

    (*pHead).value = user_in_1;
    (*pHead).pNext = pSecond;
    (*pSecond).value = user_in_2;
    (*pSecond).pNext = pTail;
    (*pTail).value = user_in_3;
    (*pTail).pNext = nullptr;


    cout << "Linked list in order:" << endl;
    Node *pCurrent = pHead;
    while (pCurrent != nullptr){
        cout << (*pCurrent).value << " ";
        pCurrent = (*pCurrent).pNext;
    }
    cout << endl;

    cout << "Linked list in reverser order:" << endl;
    for (int i = 2; i >= 0; i--){
        Node *pReverse = pHead;
        int index = 0;
        while (index < i && pReverse != nullptr){
            index ++;
            pReverse = (*pReverse).pNext;
        }
        if (pReverse != nullptr){
            cout << (*pReverse).value << " ";
        }
        delete pReverse;
    }

    delete pArray;
    delete pHead;
    delete pSecond;
    delete pTail;
    delete pCurrent;

    return 0;
}