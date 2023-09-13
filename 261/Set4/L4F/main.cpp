# include <iostream>
# include "LinkedList.hpp"

using namespace std;

int main(){
    
    LinkedList<int> test1;

    cout << test1.size() << endl;

    test1.pushFront(1);
    test1.pushBack(2);
    test1.pushFront(3);
    test1.pushBack(4);
    test1.pushFront(5);
    test1.pushBack(6);

    cout << test1.size() << endl;

    for (unsigned int i = 0; i < test1.size(); i++){
        cout << test1.at(i) << " ";
    }

    cout << endl;

    LinkedList<int> test2;

    cout << test2.size() << endl;

    test2 = test1;

    cout << test1.size() << endl;
    cout << test2.size() << endl;

    test1.pushFront(7);
    test1.pushBack(8);

    cout << test1.size() << endl;
    
    for (unsigned int i = 0; i < test1.size(); i++){
        cout << test1.at(i) << " ";
    }

    cout << endl;

    cout << test2.size() << endl;
    for (unsigned int i = 0; i < test2.size(); i++){
        cout << test2.at(i) << " ";
    }

    cout << endl;

    LinkedList<int> test3(test1);

    cout << test1.size() << endl;
    cout << test2.size() <<  endl;
    cout << test3.size() << endl;

    test1.pushFront(9);
    test1.pushBack(10);

    cout << test1.size() << endl;
    cout << test2.size() <<  endl;
    cout << test3.size() << endl;

    for (unsigned int i = 0; i < test1.size(); i++){
        cout << test1.at(i) << " ";
    }

    cout << endl;

    for (unsigned int i = 0; i < test2.size(); i++){
        cout << test2.at(i) << " ";
    }

    cout << endl;

    for (unsigned int i = 0; i < test3.size(); i++){
        cout << test3.at(i) << " ";
    }

    cout << endl;

    LinkedList<string> test4;

    test4.pushFront("is");
    test4.pushBack("working");
    test4.pushFront("This");
    test4.pushBack("now");

    for (unsigned int i = 0; i < test4.size(); i++){
        cout << test4.at(i) << " ";
    }

    cout << endl;

    test1.~LinkedList();
    test2.~LinkedList();
    test3.~LinkedList();
    test4.~LinkedList();

    return 0;
}