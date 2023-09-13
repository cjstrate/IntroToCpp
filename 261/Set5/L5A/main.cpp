# include <iostream>
# include "DoublyLinkedList.hpp"
using namespace std;

int main(){

    DoublyLinkedList<int> test;
    test.insert(0,6);
    test.insert(0,5);
    test.insert(5,7);
    test.insert(-3,1);
    test.insert(1,2);
    test.insert(2,9);
    test.insert(2,3);
    test.print();
    cout << endl;
    test.printReverse();
    cout << endl;
    test.set(3,4);
    test.print();
    cout << endl;
    test.remove(-2);
    test.remove(9);
    test.remove(2);
    cout << test.get(2) << endl;
    cout << test.size() << endl;
    test.print();
    test.~DoublyLinkedList();
    return 0;
} 