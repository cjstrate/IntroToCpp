/* CSCI 261: Assignment 3: A3 - Green Eggs and Ham
 *
 * Author: Carter Strate
 * Resources used: Jordan Pettyjohn, worded together on psudocode and debugging
 *
 * The purpose of this program is to count the number of times every letter appears in a text file as well as to find the number of unique words and number of words in general. Additonally it will find teh most frequent and least 
 * frequent letters in the file.
 */ 
#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string prompt_user_for_filename();

bool open_file(ifstream &input, string inputName);

vector<string> read_words_from_file(ifstream &input);

void remove_punctuation(vector<string> &words, const string PUNCTUATION);

void capitalize_words(vector<string> &words);

vector<string> filter_unique_words(vector<string> &words);

void count_letters(unsigned int *pNums, vector<string> words);

void print_letter_counts(const unsigned int *pNUMS);

void print_max_min_letter(const unsigned int *pNUMS);
#endif