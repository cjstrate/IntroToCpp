#include <iostream>
#include "LinkedList.hpp"

using namespace std;

main() {
    DoublyLinkedList<int> test;
    test.insert(0, 6);
    test.insert(0, 2);
    test.insert(0, 7);
    test.insert(0, 9);
    test.insert(0, 5);
    test.insert(0, 1);
    test.insert(0, 8);
    test.insert(0, 3);
    test.insert(0, 4);

    test.print();
    cout << endl;
    test.callMergeSort();
    test.print();
    return 0;
}