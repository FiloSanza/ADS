#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <functional>
#include <vector>

using namespace std;

template<typename T, typename Comp = less<T>>
class Heap {
public:
    Heap();
    Heap(const vector<T>& in);

    T pop();
    T top();
    void insert(T value);
    bool empty();

private:
    vector<T> data;
    Comp cmp;

    void heapify(int idx);
    int left(int idx);
    int right(int idx);
    int parent(int idx);
};

#endif