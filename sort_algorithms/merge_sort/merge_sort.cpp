#include "merge_sort.h"

template<typename T, typename Comp = std::less<T>>
void merge_sort(vector<T>& v, Comp c) {
    vector<int> buffer(v.size());
    _merge_sort_rec(v, 0, v.size() - 1, c, buffer);    
}


template<typename T, typename Comp>
void _merge_sort_rec(vector<T>& v, size_t l, size_t r, Comp c, vector<int>& buffer) {
    if(l == r) return;

    size_t mid = (l + r) / 2;
    _merge_sort_rec(v, l, mid, c, buffer);
    _merge_sort_rec(v, mid + 1, r, c, buffer);
    _merge_sort_merge(v, l, mid + 1, r, buffer);
}

template<typename T>
void _merge_sort_merge(vector<T>& v, size_t l, size_t mid, size_t r, vector<int>& buffer) {
    size_t N = (r - l + 1);
    size_t a = l, b = mid;
    size_t idx = 0;

    while (idx < N) {
        if(a < mid && (b > r || v[a] < v[b]))
            buffer[idx++] = v[a++];
        else
            buffer[idx++] = v[b++];
    }

    for(size_t i=0; i<N; i++)
        v[i + l] = buffer[i];
}

template void merge_sort(vector<int>& v, std::less<int> c);