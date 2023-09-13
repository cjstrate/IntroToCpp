/*
 * main.cpp
 *
 * Includes the main() function for the trie project.
 *
 * This code creates the executable run-main.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <cstddef>
#include <algorithm>
#include <chrono>

#include "trie.h"

using namespace std;

int main() {
    // You can use this main() to run your own analysis or testing code.

// You can uncomment the code below to read in a large word list and insert
// them all into your trie, to set up your own tests.

    ifstream fin("dictionary.txt");
    if (!fin) {
        cout << "Error opening dictionary.txt, exiting." << endl;
        return -1;
    }

    vector<string> words;
    while (fin) {
        string s;
        fin >> s;
        if (!s.empty()) words.push_back(s);
    }
    fin.close();
    vector<string> copyWords = words;

    trie trieTest1;
    trie trieTest2;
    trie trieTest3;
    trie trieTest4;

    set<string> setTest;
    unordered_set<string> hashTest;

    //Comment this out for ordered test, uncomment for random text
    random_shuffle(words.begin(), words.end());

    cout << "Data table 1" << endl;
    cout << endl;
    for(int i = 1; i <= 4; i++) {
        cout << "Trial " << i << " & ";

    auto start_time0 = chrono::high_resolution_clock::now();
    for(string s : words) {
        if (i == 1) {
            trieTest1.insert(s);
        } else if (i ==2) {
            trieTest2.insert(s);
        } else if (i == 3) {
            trieTest3.insert(s);
        } else {
            trieTest4.insert(s);
        }
}
    auto stop_time0 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed0 = stop_time0 - start_time0;
    //cout << "Trie Insert: " << elapsed0.count() / words.size() << endl;
    cout << elapsed0.count() << " & ";

    auto start_time1 = chrono::high_resolution_clock::now();
    for(string s : words) {
        setTest.insert(s);
    }
    auto stop_time1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = stop_time1 - start_time1;
    //cout << "Set Insert: " << elapsed1.count() / words.size() << endl;
    cout << elapsed1.count() << " &";

    auto start_time2 = chrono::high_resolution_clock::now();
    for(string s : words) {
        hashTest.insert(s);
    }
    auto stop_time2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = stop_time2 - start_time2;
    //cout << "Hash Insert: " << elapsed2.count() / words.size() << endl;
    cout << elapsed2.count()<< " \\" << "\\" << endl;

    setTest.clear();
    hashTest.clear();
    cout << "\\hline" << endl;
    }

    cout << "Data table 2" << endl;
    cout << endl;

    for(int i = 1; i <= 4; i++) {
    cout << "Trial " << i << " & ";

    auto start_time3 = chrono::high_resolution_clock::now();
    for(string s : copyWords) {
        trieTest1.contains(s);
    }
    auto stop_time3 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed3 = stop_time3 - start_time3;
    //cout << "Trie Insert: " << elapsed0.count() / words.size() << endl;
    cout << elapsed3.count() << " & ";

    auto start_time4 = chrono::high_resolution_clock::now();
    for(string s : copyWords) {
        setTest.find(s);
    }
    auto stop_time4 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed4 = stop_time4 - start_time4;
    //cout << "Set Insert: " << elapsed1.count() / words.size() << endl;
    cout << elapsed4.count() << " &";

    auto start_time5 = chrono::high_resolution_clock::now();
    for(string s : copyWords) {
        hashTest.count(s);
    }
    auto stop_time5 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed5 = stop_time5 - start_time5;
    //cout << "Hash Insert: " << elapsed2.count() / words.size() << endl;
    cout << elapsed5.count()<< " \\" << "\\" << endl;
   
    cout << "\\hline" << endl;
    }

    cout << "Node Count: ";
    //trieTest1.countNode();
    cout << endl;

    trie testTrie5;

    for (string s : copyWords) {
        testTrie5.insert(s);
    }

    unsigned int leafCount = 0;
    for(string s : copyWords) {
        if (testTrie5.is_prefix(s)) {
            leafCount++;
        }
    }

    cout << "Leaf Count: "<< leafCount << endl;

    return 0;
}