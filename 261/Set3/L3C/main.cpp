/* CSCI 261: Assignment 3: L3C
 *
 * Author: Carter Strate
 * Resources used: None
 *
 * The purpose of this program is to undertand how pointer work (specifically when you get the address vs the value)
 * 
 */
#include <iostream>

using namespace std;

main () {
    int iNum = 9;
    double dNum = 14.25;

    int *pINum1 = &iNum;
    //int *pINum2 = &dNum; main.cpp:10:20: error: cannot convert 'double*' to 'int*' in initialization

    double *pDNum = &dNum;

    cout << "iNum Address: " << pINum1 << endl;
    cout << "pINum1 Value: " << *pINum1 << endl;

    cout << endl;

    cout << "dNum Address: " << pDNum << endl;
    cout << "dNum value: " << *pDNum << endl;

    cout << endl;

    int *pINum2 = pINum1;
    cout << "pINum2 Address: " << pINum2 << endl;
    cout << "pINum2 Value: " << *pINum2 << endl;

    cout << endl;
    *pINum2 = 12;
    cout << "iNum: " << iNum << ", pINum1: " << *pINum1 << ", and pINum2: " << *pINum2 << "." << endl;

    return 0;
}