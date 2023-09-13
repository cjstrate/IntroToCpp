/*
 * stack.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Your Name
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_

using namespace std;

template <typename T>
class stack {
  public:
    T top(); // non-inline, implemented in stack-stage1.cpp

    // inline definitions, doing nothing at the moment
    void push(const T value);
    void pop();
    int size();
    bool is_empty();

    stack();
    stack(const stack &original);
    stack operator=(const stack &rhs);
    ~stack();

  private:
    T *_data = new T[2];
    unsigned int _size;
    unsigned int _capacity;
};

#endif

template <typename T>
stack<T>::stack(){
    _size = 0;
    _capacity = 2;
}

template <typename T>
stack<T>::stack(const stack<T> &original){
    _size = original._size;
    _capacity = original._capacity;
    T *tempArray = new T[_capacity];

    for (unsigned int i = 0; i < _size; i++){
        tempArray[i] = original._data[i];
    }

    _data = tempArray;
    tempArray = nullptr;
}

template <typename T>
stack<T>::~stack(){
    delete[] _data;
    _data = nullptr;
}

template <typename T>
void stack<T>::push(const T value){
    
    if (_size == _capacity){
        _capacity = _capacity * 1.5;
        T *tempArray = new T[_capacity];
        
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

template <typename T>
stack<T> stack<T>::operator=(const stack<T> &rhs){
    _size = rhs._size;
    _capacity = rhs._capacity;

    
    T *tempArray = new T[_capacity];

    for (unsigned int i = 0; i < _size; i++){
        tempArray[i] = rhs._data[i];
    }

    _data = tempArray;
    tempArray = nullptr;

    return *this;
}

template <typename T>
void stack<T>::pop(){
    if(_size != 0){
        _size--;
    }
}

template <typename T>
int stack<T>::size(){
    return _size;
}

template <typename T>
bool stack<T>::is_empty(){
    if (_size == 0){
        return true;
    }
    return false;
}

template <typename T>
T stack<T>::top(){   
    if (_size != 0){
        return _data[_size - 1];
    }
    return _data[0];
}