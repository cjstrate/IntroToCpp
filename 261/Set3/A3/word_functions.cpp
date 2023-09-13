/* CSCI 261: Assignment 3: A3 - Green Eggs and Ham
 *
 * Author: Carter Strate
 * Resources used: Jordan Pettyjohn, worded together on psudocode and debugging
 *
 * The purpose of this program is to count the number of times every letter appears in a text file as well as to find the number of unique words and number of words in general. Additonally it will find teh most frequent and least 
 * frequent letters in the file.
 */

#include "word_functions.h"
#include <set>
#include <iomanip>

string prompt_user_for_filename() {
    
    cout << "Input a filename: " << endl;
    string fileIn;
    cin >> fileIn;
    return fileIn;

}

bool open_file(ifstream &fileIn, string fileName){
    
    fileIn.open(fileName);

    if (fileIn.fail() ) {
        return 0;
    } else {
        return 1;
    }
}

vector<string> read_words_from_file(ifstream &fileIn){
   
    string word;
    vector<string> words;

    int count = 0;

    while (fileIn >> word) {
        words.push_back(word);
        count++;
    }

    return words;

}

void remove_punctuation(vector<string> &words, const string PUNCTUATION){
   
    for (int i = 0, len1 = words.size(); i < len1; i++) {
        int j = 0;
        while (words[i][j] != '\0') {
            if (ispunct(words[i][j])) {
                words[i].erase(j--, 1);
            }
            j++;
        }
    }
}

void capitalize_words(vector<string> &words){
    
    for (int i = 0, len = words.size(); i < len; i++) {
        string upWord;
        int j = 0;
        while (words[i][j] != '\0') {
            upWord += toupper(words[i][j]);
            j++;
        }
        words[i] = upWord;
    }

}

vector<string> filter_unique_words(vector<string> &words){
    
    set<string> tempSet;
    vector<string> unique;
    
    for (int i = 0, len = words.size(); i < len; i++) {
        tempSet.insert(words[i]);
    }

    copy(tempSet.begin(), tempSet.end(), back_inserter(unique));

    return unique;

}

void count_letters(unsigned int *pNums, const vector<string> WORDS){

    const char ALPHABET[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for (int i = 0, len = WORDS.size(); i < len; i++) {
        for (int a = 0; a < 26; a++) {
            int test = 0;
            for ( char j : WORDS[i]) {
                if ( j == ALPHABET[a]) {
                    test++;
                }
            }

            pNums[a] += test;
        }
    }
}

void print_letter_counts(const unsigned int *pNUMS){
    
    const char ALPHABET[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    for (int i = 0; i < 26; i++) {
        cout << ALPHABET[i] << " " << pNUMS[i] << endl;
    }
}

void print_max_min_letter( const unsigned int *pNUMS) {
    
    const char ALPHABET[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    unsigned int max = 0;
    unsigned int min = RAND_MAX;

    char charMax;
    char charMin;

    double total = 0;

    for (int i = 0; i < 26; i++) {
        if (pNUMS[i] > max) {
            max = pNUMS[i];
            charMax = ALPHABET[i];
        } else if (pNUMS[i] < min) {
            min = pNUMS[i];
            charMin = ALPHABET[i];
        }

        total += pNUMS[i];
    }
    cout << fixed;
    cout << setprecision(3);
    cout << "Least Frequent Letter: " << charMin << " " << min << " (  " << min / total * 100 << "%)" << endl;
    cout << " Most Frequent Letter: " << charMax << " " << max << " (  " << max / total * 100 << "%)" << endl;

}