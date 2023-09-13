# include <iostream>
# include "BinarySearchTree.hpp"

using namespace std;

int main(){

    BinarySearchTree jerry;

    jerry.insert(6);
    jerry.insert(5);
    jerry.insert(7);
    jerry.insert(1);
    jerry.insert(2);
    jerry.insert(9);
    jerry.insert(3);

    cout << "done" << endl;

    return 0;
}