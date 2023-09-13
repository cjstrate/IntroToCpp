# include <iostream>
# include "TreeNode.hpp"

using namespace std;

class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(const int VAL);
        int size() const;
        Node* getRoot();
        void printLeft();
        void printRight();
        void printInOrder();
    private:
        unsigned int Size;
        Node *pRoot;
};

BinarySearchTree::BinarySearchTree(){
    pRoot = nullptr;
    Size = 0;
}


BinarySearchTree::~BinarySearchTree(){
    Size = 0;
    pRoot = nullptr;
}

int BinarySearchTree::size() const{
    return Size;
}

void BinarySearchTree::insert(const int VAL){
    
    if (Size == 0){
        pRoot = new Node;
        pRoot -> value = VAL;
        pRoot -> pLeft = nullptr;
        pRoot -> pRight = nullptr;
        pRoot -> pParent = nullptr;
        return;
        Size++;
    }


    if (VAL < pRoot -> value){
        if (pRoot -> pLeft == nullptr){
            Node *pNew = new Node;
            pRoot -> pLeft = pNew;
            pNew -> value = VAL;
            pNew -> pParent = pRoot;
            Size++;
            while (pRoot -> pParent != nullptr){
                pRoot = pRoot -> pParent;
            }
            return;
        } else {
            pRoot = pRoot -> pLeft;
            insert(VAL);
        }
    } else {
        if (pRoot -> pRight == nullptr){
            Node *pNew = new Node;
            pRoot -> pRight = pNew;
            pNew -> value = VAL;
            pNew -> pParent = pRoot;
            Size++;
            while (pRoot -> pParent != nullptr){
                pRoot = pRoot -> pParent;
            }
            return;
        } else {
            pRoot = pRoot -> pLeft;
            insert(VAL);
        }
    }
}

Node* BinarySearchTree::getRoot(){
    return pRoot;
}

void BinarySearchTree::printLeft(){
    if (pRoot != nullptr){
        cout << pRoot -> value << " ";
        pRoot = pRoot -> pLeft;
        printLeft();
    }
    while (pRoot -> pParent != nullptr){
        pRoot = pRoot -> pParent;
    }
}

void BinarySearchTree::printRight(){
    if (pRoot != nullptr){
        cout << pRoot -> value << " ";
        pRoot = pRoot -> pRight;
        printRight();
    }
    while (pRoot -> pParent != nullptr){
        pRoot = pRoot -> pParent;
    }
}

void BinarySearchTree::printInOrder(){
    printLeft();
    cout << pRoot -> value << " ";
    printRight();
    cout << endl;
}