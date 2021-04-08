#include "insertion_sort.h"

template<typename T, typename Comp = std::less<T>>
void insertion_sort(vector<T>& v, Comp c) {
    if(v.empty()) return;   
    
    auto N = v.size();
    int j = 0;

    for(size_t i=1; i<N; i++) {
        T key = v[i];
        j = i-1;

        while(j >= 0 && c(key, v[j])) {
            swap(v[j], v[j + 1]);
            --j;
        }

        v[j + 1] = key; 
    }
}

template void insertion_sort(vector<int>& v, std::less<int> c);