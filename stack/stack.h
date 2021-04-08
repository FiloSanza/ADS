#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <algorithm>

template <typename T>
class Stack {
public:
    Stack();
    
    T pop();
    void push(const T& value);
    bool empty();
private:
    T* data;
    size_t top;
    size_t capacity;

    void _realloc();
};

#endif