/* CSCI 261: Assignment 3: L3D
 *
 * Author: Carter Strate
 * Resources used: Andrew Hett, LOTS of help debugging
 *
 * The purpose of this progam is write a series of funtions that manipulate arrays on the free store
 * 
 */

#include "array_functions.h"
# include <iostream>
using namespace std;

void array_allocate(int* &pArray, const int INIT_SIZE){
    pArray = new int[INIT_SIZE];
}

int array_get_element_at(int *pArray, const int SIZE, const int POS){
    if (!(POS <= SIZE && POS >= 0)){
        return 0;
    } else {
        return pArray[POS];
    }
}

void array_set_element_at(int *pArray, const int SIZE, const int POS, const int VALUE){
    if (!(POS <= SIZE && POS >=0)){
    } else{
        pArray[POS] = VALUE;
    }
}

void array_deallocate(int* &pArray, int &size){
    delete[] pArray;
    size = 0;
    pArray = nullptr;
}

void array_insert_at_position(int* &pArray, int &size, const int POS, const int VALUE){
    size++;
    int *pNewArray = new int[size];
    for (int q = 0; q < (size - 1) ; q++){
        pNewArray[q] = pArray[q];
    }
    if (POS < size && POS >= 0){
        for (int i = size - 1; i > POS; i--){
            pNewArray[i] = pNewArray[i - 1];
        }
        pNewArray[POS] = VALUE;
    }
     else if (POS >= size){
        pNewArray[size -1] = VALUE;
    } else if (POS < 0){
        for (int k = size - 1; k > 0; k--){
            pNewArray[k] = pNewArray[k - 1];
        }
        pNewArray[0] = VALUE;
    }
    delete[] pArray;
    pArray = pNewArray;
}

int array_min(int *pArray, const int SIZE){
    int min = 0;
    
    if (SIZE == 0){
        return 0;
    }

    for (int i = 0; i < SIZE; i++){
        if (i == 0){
            min = pArray[0];
        } else if (pArray[i] < min){
            min = pArray[i];
        }
    }

    return min;
}

int array_max(int *pArray, const int SIZE){
    int max = 0;

    if (SIZE == 0){
        return 0;
    }

    for (int i = 0; i < SIZE; i++){
        if (i == 0){
            max = pArray[0];
        } else if (pArray[i] > max){
            max = pArray[i];
        }
    }

    return max;
}

int array_find(int *pArray, const int SIZE, const int TARGET){
    
    for (int i = 0; i < SIZE; i++){
        if (pArray[i] == TARGET){
            return i;
        }
    }

    return -1;
}

void array_remove_from_position(int* &pArray, int &size, const int POS){
    int index = POS;
    size--;
    if (size <= 0){
        size = 0;
        return;
    }
    int *pNewArray = new int[size];
    if (POS < 0){
        index = 0;
    } else if (POS > size){
        index = size;
    }

    int new_array_index = 0;
    for (int i = 0; i <= size; i++){
        if (i != index){
            pNewArray[new_array_index] = pArray[i];
            new_array_index ++;
        }
    }
    delete[] pArray;
    pArray = pNewArray;
}

