#include "stack.h"

template<typename T>
Stack<T>::Stack() : top(0), capacity(1) {
    data = new T[1];
}

template<typename T>
T Stack<T>::pop() {
    if(empty()) throw;
    return data[--top];
}

template<typename T>
void Stack<T>::push(const T& value) {
    if(top == capacity) _realloc();
    data[top++] = value;
}

template<typename T>
bool Stack<T>::empty() {
    return top == 0;
}

template<typename T>
void Stack<T>::_realloc() {
    capacity *= 2;
    auto new_data = new T[capacity];
    std::copy(data, data + top, new_data);

    if(data) delete[] data;

    data = new_data;
}

template class Stack<int>;