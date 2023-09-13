#ifndef TREENODE_HPP
#define TREENODE_HPP


struct Node {
    Node *pParent;
    Node *pLeft;
    Node *pRight;
    int value;
};

#endif 