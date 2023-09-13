/*
 * trie.h
 *
 * Declaration of the trie class.
 * 
 * Author: <your name here>
 */

#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>

using namespace std;

class trie {
private:
    class Node {
        public:
            bool terminal;
            Node* children[26];
            
    };
    Node* root = new Node;
    Node* getNode(){
        Node* newNode = new Node;
        newNode -> terminal = false;
        for (int i = 0; i < 26; i++){
            newNode -> children[i] = nullptr;
        }
        return newNode;
    }
    void extendHelper(Node* &start, string prefix, string &word, vector<string> &result){
        if (start == nullptr){
            return;
        }
        if (start -> terminal){
            result.push_back(word);
        }
        for (int i = 0; i < 26; i++){
            word = prefix;
            if (start -> children[i] != nullptr){
                word = word + char('a' + i);
                extendHelper(start -> children[i], word, word, result);
            }
        }
    }
public:
    trie();
    //~trie();
    void insert(const string &s);
    bool contains(const string &s);
    bool is_prefix(const string &s);
    void extend(const string &prefix, vector<string> &result);
};

#endif
