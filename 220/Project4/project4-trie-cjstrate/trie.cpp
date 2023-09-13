/*
 * trie.cpp
 *
 * Method definitions for the trie class.
 *
 * Author: <your name here>
 */

#include <string>
#include "trie.h"
#include <iostream>

using namespace std;

trie::trie(){
    root -> terminal = false;
    for (int i = 0; i < 26; i++){
        root -> children[i] = nullptr;
    }
}

// trie::~trie(){

// }

void trie::insert(const string &s){
    Node* pTrav = new Node;
    pTrav = root;
    for (int i = 0; i < s.length(); i++){
        int index = s[i] - 'a';
        if (!pTrav -> children[index]){
            pTrav -> children[index] = getNode();
        }
        pTrav = pTrav -> children[index];
    }
    pTrav -> terminal = true;
}

bool trie::contains(const string &s){
    Node* pTrav = new Node;
    pTrav = root;
    for (int i = 0; i < s.length(); i++){
        int index = s[i] - 'a';
        if (pTrav -> children[index] == nullptr){
            return false;
        }
        pTrav = pTrav -> children[index];
    }
    return pTrav -> terminal;
}

bool trie::is_prefix(const string &s){
    Node* pTrav = new Node;
    pTrav = root;
    for (int i = 0; i < s.length(); i++){
        int index = s[i] - 'a';
        if (pTrav -> children[index] == nullptr){
            return false;
        }
        pTrav = pTrav -> children[index];
    }
    return true;
}

void trie::extend(const string &prefix, vector<string> &result){
    if (!is_prefix(prefix)){
        return;
    }

    Node* pTrav = new Node;
    pTrav= root;
    for (int i = 0; i < prefix.length(); i++){
        int index = prefix[i] - 'a';
        pTrav= pTrav -> children[index];
    }

    string word = prefix;

    extendHelper(pTrav, prefix, word, result);
}