/*
 * main-stage3.cpp
 *
 * Includes the main() function for the stack project (stages 2 & 3).
 *
 * This code is included in the build target "run-stage3-main", and
 * in the convenience targets "stage2", and "stage3".
 */

#include <iostream>
# include <chrono>

#include "stack-stage3.h"

using namespace std;

double time_n_pushes(unsigned n) { 
    stack<unsigned> s; 
   
    // get starting clock value  
    auto start_time = chrono::system_clock::now(); 
 
    for (unsigned i = 0; i < n; i++) { 
        s.push(i); 
    } 
 
    // get ending clock value 
    auto stop_time = chrono::system_clock::now(); 
    chrono::duration<double> elapsed = stop_time - start_time; 
    return elapsed.count(); 
} 

int main(){
    
    double data1 = time_n_pushes(10000);
    double data2 = time_n_pushes(20000);
    double data3 = time_n_pushes(30000);
    double data4 = time_n_pushes(40000);
    double data5 = time_n_pushes(50000);
    double data6 = time_n_pushes(60000);
    double data7 = time_n_pushes(70000);
    double data8 = time_n_pushes(80000);
    double data9 = time_n_pushes(90000);
    double data10 = time_n_pushes(100000);

    double avg1 = data1 / 10000;
    double avg2 = data2 / 20000;
    double avg3 = data3 / 30000;
    double avg4 = data4 / 40000;
    double avg5 = data5 / 50000;
    double avg6 = data6 / 60000;
    double avg7 = data7 / 70000;
    double avg8 = data8 / 80000;
    double avg9 = data9 / 90000;
    double avg10 = data10 / 100000;

    cout << "10,000 pushes: " << avg1 * 1000000 << " microseconds" << endl;
    cout << "20,000 pushes: " << avg2 * 1000000 << " microseconds" << endl;
    cout << "30,000 pushes: " << avg3 * 1000000 << " microseconds" << endl;
    cout << "40,000 pushes: " << avg4 * 1000000 << " microseconds" << endl;
    cout << "50,000 pushes: " << avg5 * 1000000 << " microseconds" << endl;
    cout << "60,000 pushes: " << avg6 * 1000000 << " microseconds" << endl;
    cout << "70,000 pushes: " << avg7 * 1000000 << " microseconds" << endl;
    cout << "80,000 pushes: " << avg8 * 1000000 << " microseconds" << endl;
    cout << "90,000 pushes: " << avg9 * 1000000 << " micorseconds" << endl;
    cout << "100,000 pushes: " << avg10 * 1000000 << " microseconds" << endl;

    return 0;
}
