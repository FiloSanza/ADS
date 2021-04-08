#include "selection.h"

#include <iostream>

using namespace std;

template<typename T, typename Comp = less<T>>
T get_nth_element(vector<T>& v, size_t nth, Comp c) {
    return _get_nth_element(v, 0, v.size()-1, nth, c);
}

template<typename T, typename Comp = less<T>>
T _get_nth_element(vector<T>& v, size_t l, size_t r, size_t nth, Comp c) {
    if(r - l + 1 <= 5) {
        sort(v.begin() + l, v.begin() + r + 1, c);
        return v[l + nth];
    }

    vector<T> m;
    for(size_t i=l; i < r; i+=5) {
        size_t mid = (min(i + 5, r) + i) / 2;
        sort(v.begin() + i, v.begin() + min(i + 5, r + 1), c);
        m.push_back(v[mid]);
    }

    size_t N = m.size();
    T median = _get_nth_element(m, 0, N-1, N / 2);
    size_t pivot = _partition(v, l, r, median, c);

    size_t k = pivot - l;

    if(nth == k) return v[pivot];
    else if(nth < k) return _get_nth_element(v, l, pivot - 1, nth, c);
    else return _get_nth_element(v, pivot + 1, r, nth - k - 1, c);
}

template<typename T, typename Comp>
int _partition(vector<T>& v, int l, int r, T key, Comp c) {
    for(int i=l; i<=r; i++) {
        if(v[i] == key) {
            swap(v[i], v[r]);
            break;
        }
    }
    
    int i = l - 1;

    for(int j = l; j < r; j++) {
        if(c(v[j], key)) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i+1], v[r]);
    return i+1;
}

template int get_nth_element(vector<int>& v, size_t nth, less<int> c);