/* CSCI 261: Assignment 3: L3B
 *
 * Author: Carter Strate
 * Resources used: Jordan Pettyjohn, debugging
 *
 * The purpose of this progarm was to write a sereis of funcitons to manipulate strings.
 * 
 */
#include "string_functions.h"

int string_length(const string STR)  {
    int result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';
    result = STR[IDX];
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    result = LEFT + RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    result.insert(IDX, TO_INSERT);
    return result;
}

int string_find(const string STR, const char C)  {
    int result = -1;
    // TODO 04: set result to the index of the first occurrence of the character
    result = STR.find(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    // TODO 05: set result to be a substring starting at index of given length
    result = STR.substr(IDX,LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    // TODO 06: set result to be the string with the given text replaced
    int IDX = STR.find(TEXT_TO_REPLACE);
    if (IDX == -1){
        return result;
    }
    int LEN = string_length(TEXT_TO_REPLACE);
    result.replace(IDX, LEN, REPLACE_WITH);
    return result;
}

string string_first_word(const string STR) {
    string result = STR;
    string temp;
    int i = 0;
    // TODO 07: set result to the first word from the string
    while (STR[i] != ' ' && STR[i] != '\0'){
        temp += STR[i];
        i++;
    }
    result = temp;
    return result;
}

string string_remove_first_word(const string STR)  {
    string result = STR;
    int LEN;
    // TODO 08: set result to be the string with the first word removed
    string TO_REPLACE = string_first_word(STR);
    LEN = string_length(TO_REPLACE);
    if (STR[LEN] == ' '){
        TO_REPLACE = TO_REPLACE + ' ';
    }
    result = string_replace(STR, TO_REPLACE, "");
    return result;
}

string string_second_word(const string STR)  {
    string result = STR;
    string temp;
    // TODO 09: set result to be the second word from the string
    int i = 0;
    int num_spaces = 1;
    while (STR[i] != '\0'){
        if (num_spaces == 2 && STR[i] != ' '){
            temp += STR[i];
        }
        if (STR[i] == ' '){
            num_spaces++;
        }
        i++;
    }

    result = temp;
    return result;
}

string string_third_word(const string STR)  {
    string result = STR;
    string temp;
    // TODO 10: set result to be the third word from the string
    int i = 0;
    int num_spaces = 1;
    while (STR[i] != '\0'){
        if (num_spaces == 3 && STR[i] != ' '){
            temp += STR[i];
        }
        if (STR[i] == ' '){
            num_spaces++;
        }
        i++;
    }

    result = temp;
    return result;
}

string string_nth_word(const string STR, const int N)  {
    string result = STR;
    string temp;
    // TODO 11: set result to be the nth word from the string
    int i = 0;
    int num_spaces = 1;
    while (STR[i] != '\0'){
        if (num_spaces == N && STR[i] != ' '){
            temp += STR[i];
        }
        if (STR[i] == ' '){
            num_spaces++;
        }
        i++;
    }

    result = temp;
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    // TODO 12: set result to be the string with all instances of TARGET replaced
    int i = 0;
    while (STR[i] != '\0'){
        if (STR[i] == TARGET){
            result[i] = REPLACEMENT;
        }
        i++;
    }
    return result;
}

string string_to_lower(const string STR) {
    string result = STR;
    // TODO 13: convert all characters to lower case
    string temp;
    int i = 0;
    while (STR[i] != '\0'){
        temp += tolower(STR[i]);
        i++;
    }
    return temp;
}

string string_to_upper(const string STR) {
    string result = STR;
    // TODO 14: convert all characters to upper case
    string temp;
    int i = 0;
    while (STR[i] != '\0'){
        temp += toupper(STR[i]);
        i++;
    }
    return temp;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    // TODO 15: compare LHS and RHS
    if (LHS == RHS){
        result = 0;
    } else if (LHS == string_to_lower(RHS)){
        result = 1;
    } else if (LHS == string_to_upper(RHS)){
        result = -1;
    } else if (LHS.length() < RHS.length()){
        result = -1;
    } else if (LHS.length() > RHS.length()){
        result = 1;
    }
    return result;
}