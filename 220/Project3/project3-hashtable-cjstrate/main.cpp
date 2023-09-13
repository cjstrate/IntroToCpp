/*
 * main.cpp
 *
 * Includes the main() function for the hashtable project.
 *
 * This code is included in the default build target.  It
 * produces the program run-main.
*/

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include <chrono>

#include "hashtable.h"
#include "hash_functions.h"

using namespace std;

int main() {

    // Hash functions
    hash0 h0;
    hash1 h1;
    hash2 h2;
    hash3 h3;
    hash4 h4;

    //create hashtables, change from hash0 to hash4 to test all hash functions
    hashtable<string, hash4> testDict;
    hashtable<string, hash4> testSeq;
    hashtable<string, hash4> testRand;

    //cout << "1" << endl;

    //Load the data
    ifstream file1("dictionary.txt");
    vector<string> dataDict;
    while(!file1.eof()) {
        string sDict;
        file1 >> sDict;
        dataDict.push_back(sDict);
    }

    //cout << "2" << endl;

    ifstream file2("sequence.txt");
    vector<string> dataSeq;
    while(!file2.eof()) {
        string sSeq;
        file2 >> sSeq;
        dataSeq.push_back(sSeq);
    }

    //cout << "3" << endl;

    ifstream file3("random.txt");
    vector<string> dataRand;
    while(!file3.eof()) {
        string sRand;
        file3 >> sRand;
        dataRand.push_back(sRand);
    }
   
    //insert strings into hashtable
    for(string sDict : dataDict) {
        testDict.insert(sDict);
    }

    for(string sSeq : dataSeq) {
        testSeq.insert(sSeq);
    }

    for(string sRand : dataRand) {
        testRand.insert(sRand);
    }

    //This is a test input
    string testString("ZZZZ");

    //time tests for insert, find, and remove

    //test Dictionary Insert
    auto start_time0 = chrono::system_clock::now();
    testDict.insert(testString);
    auto stop_time0 = chrono::system_clock::now();
    chrono::duration<double> elapsed0 = stop_time0 - start_time0;
    cout << "Dict Insert: " << elapsed0.count() << endl;

    //test Dictionary Find
    auto start_time1 = chrono::system_clock::now();
    testDict.contains(testString);
    auto stop_time1 = chrono::system_clock::now();
    chrono::duration<double> elapsed1 = stop_time1 - start_time1;
    cout << "Dict Find: " << elapsed1.count() << endl;

    //test Dictionary Remove
    auto start_time2 = chrono::system_clock::now();
    testDict.remove(testString);
    auto stop_time2 = chrono::system_clock::now();
    chrono::duration<double> elapsed2 = stop_time2 - start_time2;
    cout << "Dict Remove: " << elapsed2.count() << endl;

    //test Sequence Insert
    auto start_time3 = chrono::system_clock::now();
    testSeq.insert(testString);
    auto stop_time3 = chrono::system_clock::now();
    chrono::duration<double> elapsed3 = stop_time3 - start_time3;
    cout << "Seq Insert: " << elapsed3.count() << endl;

    //test Sequence Find
    auto start_time4 = chrono::system_clock::now();
    testSeq.contains(testString);
    auto stop_time4 = chrono::system_clock::now();
    chrono::duration<double> elapsed4 = stop_time4 - start_time4;
    cout << "Seq Find: " << elapsed4.count() << endl;

    //test Sequence Remove
    auto start_time5 = chrono::system_clock::now();
    testSeq.remove(testString);
    auto stop_time5 = chrono::system_clock::now();
    chrono::duration<double> elapsed5 = stop_time5 - start_time5;
    cout << "Seq Remove: " << elapsed5.count() << endl;

    //test Random Insert
    auto start_time6 = chrono::system_clock::now();
    testRand.insert(testString);
    auto stop_time6 = chrono::system_clock::now();
    chrono::duration<double> elapsed6 = stop_time6 - start_time6;
    cout << "Rand Insert: " << elapsed6.count() << endl;

    //test Random Find
    auto start_time7 = chrono::system_clock::now();
    testRand.contains(testString);
    auto stop_time7 = chrono::system_clock::now();
    chrono::duration<double> elapsed7 = stop_time7 - start_time7;
    cout << "Rand Find: " << elapsed7.count() << endl;

    //test Random Remove
    auto start_time8 = chrono::system_clock::now();
    testRand.remove(testString);
    auto stop_time8 = chrono::system_clock::now();
    chrono::duration<double> elapsed8 = stop_time8 - start_time8;
    cout << "Rand Remove: " << elapsed8.count() << endl;
   

    cout << "exit" << endl;
}