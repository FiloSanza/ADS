#include "heap.h"

using namespace std;

template<typename T, typename Comp>
Heap<T, Comp>::Heap() {}

template<typename T, typename Comp>
Heap<T, Comp>::Heap(const vector<T>& in) {
    if(in.empty()) return;

    data.resize(in.size());
    for(size_t i = 0; i < in.size(); i++)
        data[i] = in[i];

    for(int i=data.size() / 2 + 1; i >= 0; i--)
        heapify(i);
}

template<typename T, typename Comp>
T Heap<T, Comp>::pop() {
    T value = top();

    swap(data[0], data[data.size() - 1]);
    data.pop_back();
    heapify(0);

    return value;
}

template<typename T, typename Comp>
T Heap<T, Comp>::top() {
    return data[0];
}

template<typename T, typename Comp>
void Heap<T, Comp>::insert(T value) {
    data.push_back(value);
    int idx = data.size() - 1;

    while(idx > 0 && cmp(data[idx], data[parent(idx)])){
        swap(data[idx], data[parent(idx)]);
        idx = parent(idx);
    }
}

template<typename T, typename Comp>
void Heap<T, Comp>::heapify(int idx) {
    int small = idx;
    if(left(idx) < (int)data.size() && cmp(data[left(idx)], data[idx]))
        small = left(idx);
    if(right(idx) < (int)data.size() && cmp(data[right(idx)], data[small]))
        small = right(idx);

    if(small != idx) {
        swap(data[idx], data[small]);
        heapify(small);
    }
}

template<typename T, typename Comp>
bool Heap<T, Comp>::empty() {
    return data.empty();
}

template<typename T, typename Comp>
int Heap<T, Comp>::left(int idx) {
    return idx * 2 + 1;
}

template<typename T, typename Comp>
int Heap<T, Comp>::right(int idx) {
    return (idx + 1) * 2;
}

template<typename T, typename Comp>
int Heap<T, Comp>::parent(int idx) {
    return (idx - 1) / 2;
}

template class Heap<int, less<int>>;