# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Rectangle.hpp"
# include "LinkedList.hpp"

using namespace std;

void ascendingSort(DoublyLinkedList<Rectangle> &Object);
void descendingSort(DoublyLinkedList<Rectangle> &Object);

int main(){

    srand ( time(0) );
    
    int numRecs;
    DoublyLinkedList<Rectangle> test;
    cout << "How many Rectangles do you want to create: ";
    cin >> numRecs;
    for (int i = 0; i < numRecs; i++){
        Rectangle New;
        // since rand() generates an int to make the base and height floats
        // I generated two ints and then divided them
        New.setBase((float)rand()/(float)rand());
        New.setHeight((float)rand()/(float)rand());
        test.insert(0, New);
    }
    cout << "Original:" << endl;
    for (int i = 0; i < test.size(); i++){
        Rectangle Rec = test.get(i);
        cout << Rec.getBase() << "X" << Rec.getHeight();
        cout << " ";
    }
    cout << endl;

    ascendingSort(test);

    cout << "Ascending:" << endl;
    for (int i = 0; i < test.size(); i++){
        Rectangle Rec = test.get(i);
        cout << Rec.getBase() << "X" << Rec.getHeight();
        cout << " ";
    }
    cout << endl;

    descendingSort(test);

    cout << "Descending:" << endl;
    for (int i = 0; i < test.size(); i++){
        Rectangle Rec = test.get(i);
        cout << Rec.getBase() << "X" << Rec.getHeight();
        cout << " ";
    }
    cout << endl;

    return 0;
}

void ascendingSort(DoublyLinkedList<Rectangle> &Object){
    bool error = false;
    Rectangle New;
    Rectangle Old = Object.get(0);
    for (int i = 1; i < Object.size(); i++){
        New = Object.get(i);
        if (New < Old){
            Object.set(i - 1, New);
            Object.set(i, Old);
            error = true;
        }
        Old = New;
    }
    if (error == true){
        ascendingSort(Object);
    }
}

void descendingSort(DoublyLinkedList<Rectangle> &Object){
    bool error = false;
    Rectangle New;
    Rectangle Old = Object.get(0);
    for (int i = 1; i < Object.size(); i++){
        New = Object.get(i);
        if (Old < New){
            Object.set(i - 1 , New);
            Object.set(i, Old);
            error = true;
        }
        Old = Object.get(i);
    }
    if (error == true){
        descendingSort(Object);
    }
}