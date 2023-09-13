/*
 * stack.cpp
 *
 * Method definitions for the stack implementation.
 *
 * Author: Your Name
 */

#include "stack-stage1.h"
#include <iostream>
using namespace std;

stack::stack(){
    _size = 0;
    _capacity = 4;
}

stack::~stack(){
    delete[] _data;
    _data = nullptr;
}

void stack::push(const string value){
    
    if (_size == _capacity){
        _capacity = _capacity * 2;
        string *tempArray = new string[_capacity];
        
        for (unsigned int i = 0; i < _size; i++){
            tempArray[i] = _data[i];
        }
        delete[] _data;
        _data = tempArray;
        tempArray = nullptr;
        delete[] tempArray;
    }
    
    _size++;
    _data[_size - 1] = value;
}

void stack::pop(){
    if(_size != 0){
        _size--;
    }
}

int stack::size(){
    return _size;
}

bool stack::is_empty(){
    if (_size == 0){
        return true;
    }
    return false;
}

string stack::top(){   
    if (_size != 0){
        return _data[_size - 1];
    }

    return "/0";
}
