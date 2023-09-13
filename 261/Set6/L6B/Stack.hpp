# include <iostream>
using namespace std;

template <typename T>
class Stack {
    
    private:
        T *array;
        unsigned int Size;

    public:
        Stack();
        ~Stack();
        int getSize();
        void push(T);
        T peak();
        T pop();
        bool isEmpty();
};

template <typename T>
Stack<T>::Stack(){
    array = new T[0];
    Size = 0;
}
 
template <typename T>
Stack<T>::~Stack(){
    delete[] array;
    Size = 0;
    array = nullptr;
}

template <typename T>
int Stack<T>::getSize(){
    return Size;
}

template <typename T>
void Stack<T>::push(T value){
    Size++;
    T *arrayN = new T[Size];
    for (unsigned int i = 0; i < (Size - 1); i++){
        arrayN[i] = array[i];
        }
    arrayN[Size - 1] = value;

    delete[] array;
    array = arrayN;
}

template <typename T>
T Stack<T>::peak(){
    return array[Size - 1];
}

template <typename T>
T Stack<T>::pop(){
    Size--;
    T *arrayN = new T[Size];
    T value = array[Size];
    for (unsigned int i = 0; i < Size; i++){
        arrayN[i] = array[i];
    }

    delete[] array;
    array = arrayN;

    return value;
}

template <typename T>
bool Stack<T>::isEmpty(){
    if (Size == 0){
        return true;
    }
    return false;
}