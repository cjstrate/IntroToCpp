#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

int binarySearch(int array[], int start, int stop, int val) {
    if (stop >= start) {
        int middle = start + (stop-start) /2;

        if (array[middle] == val) {
            return middle;
        } else if (array[middle] > val) {
            return binarySearch(array, start, middle - 1, val);
        } else {
            return binarySearch(array, middle + 1, stop, val);
        }
    }
    return -1;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}




main() {
    // seed time
    srand(time(0));

    int size;
    cout << "How many randomly generated numbers do you want?" << endl;
    cin >> size;
   
    // Create an array for the haystack
    int haystack[size];

    // Assign random values for each index of the haystack
    for (int i = 0; i < size; i++) {
        int randVal = rand();
        haystack[i] = randVal;
    }

    cout << endl;

    printArray(haystack, size);
    cout << endl;

    bubbleSort(haystack, size);

    printArray(haystack, size);
    cout << endl;

    int count;
    cout << "What values would you like to search for? ";
    cin >> count;

    // Iterate through the user's choice for search.
    for (int i = 0; i < count; i++) {
        int tempVal;
        cout << "What value would you like to search for? ";
        cin >> tempVal;

        cout << endl;
        cout << "The value " << tempVal << " was located at index " << binarySearch(haystack, 0, size, tempVal) << "." << endl;

    }


    return 0;
}