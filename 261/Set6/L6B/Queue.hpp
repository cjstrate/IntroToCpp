# include <iostream>
using namespace std;
 
template <typename T>
class Queue {
    
    private:
        T *array;
        unsigned int Size;

    public:
        Queue();
        ~Queue();
        int getSize();
        void push(T);
        T peak();
        T pop();
        bool isEmpty();
};

template <typename T>
Queue<T>::Queue(){
    array = new T[0];
    Size = 0;
}

template <typename T>
Queue<T>::~Queue(){
    delete[] array;
    Size = 0;
    array = nullptr;
}

template <typename T>
int Queue<T>::getSize(){
    return Size;
}

template <typename T>
void Queue<T>::push(T value){
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
T Queue<T>::peak(){
    return array[0];
}

template <typename T>
T Queue<T>::pop(){
    Size--;
    T *arrayN = new T[Size];
    T value = array[0];

    for (unsigned int i = 1; i < Size + 1; i++){
        arrayN[i - 1] = array[i];
    }

    delete[] array;
    array = arrayN;

    return value;
}

template <typename T>
bool Queue<T>::isEmpty(){
    if (Size == 0){
        return true;
    }
    return false;
}