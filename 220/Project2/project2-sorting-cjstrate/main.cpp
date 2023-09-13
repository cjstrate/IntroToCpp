#include <iostream>
#include <cstddef>
#include <vector>
#include <chrono>

#include "sorter.h"

using namespace std;

double time_k_sort(vector<int> &vec, int k) {

    //get starting clock value
    auto start_time = chrono::system_clock::now();
    sorter(vec, k);

    // get ending clock value
    auto stop_time = chrono::system_clock::now();
    chrono::duration<double> elapsed = stop_time - start_time;
    return elapsed.count();
}
int main() {
    vector<int> testSet;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100000; i++) {
        int randVal = rand() % 100 + 1;
        testSet.push_back(randVal);
    }

    vector<int> k;
    k.push_back(2);
    k.push_back(3);
    k.push_back(4);
    k.push_back(5);
    k.push_back(8);
    k.push_back(13);

    // You can use this main() to run your own analysis or initial testing code.
    for (int i : k ) {
        cout << "Value of K is " << i << " Time Elapsed: " << time_k_sort(testSet, i) << " ms" << endl;
    }
    cout << "If you are seeing this, you have successfully run main!" << endl;
    return 0;
}