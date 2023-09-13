#include <iostream>

using namespace std;

// Function for bubble sort
void bubbleSort(int array[], int size) {
    // Iterate from zero to end
    for (int i = 0; i < size - 1; i++) {
        // Iterate from 0 to the end, ignoring the last 'i' indicies.
        for (int j = 0; j < size - i - 1; j++) {
            // If value to the left is less than the value to the right, swap
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

main() {
    int list[9] = {4,3,8,1,5,9,7,2,6};

    printArray(list, 9);

    bubbleSort(list, 9);

    printArray(list, 9);
}