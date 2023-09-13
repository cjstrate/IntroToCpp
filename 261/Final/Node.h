#ifndef NODE_HPP
#define NODE_HPP

struct Node {

    bool discovered;
 
    Node *pNorth;
    Node *pEast;
    Node *pSouth;
    Node *pWest;
};

#endif 