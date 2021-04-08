#include "quick_sort.h"

template<typename T, typename Comp = std::less<T>>
void quick_sort(vector<T>& v, Comp c) {
    _quick_sort_rec(v, 0, v.size() - 1, c);
}

template<typename T, typename Comp>
void _quick_sort_rec(vector<T>& v, int l, int r, Comp c) {
    if(l >= r) return;

    int mid = partition(v, l, r, c);
    _quick_sort_rec(v, l, mid - 1, c);
    _quick_sort_rec(v, mid + 1, r, c);
}

template<typename T, typename Comp>
int partition(vector<T>& v, int l, int r, Comp c) {
    T key = v[r];
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

template<typename T, typename Comp = std::less<T>>
void quick_sort_randomized(vector<T>& v, Comp c) {
    random_device rand_dev;
    mt19937 rng(rand_dev());
    _quick_sort_randomized_rec(v, 0, v.size() - 1, c, rng);
}

template<typename T, typename Comp>
void _quick_sort_randomized_rec(vector<T>& v, int l, int r, Comp c, mt19937& rng) {
    if(l >= r) return;

    int mid = random_partition(v, l, r, c, rng);
    _quick_sort_randomized_rec(v, l, mid - 1, c, rng);
    _quick_sort_randomized_rec(v, mid + 1, r, c, rng);
}

template<typename T, typename Comp>
int random_partition(vector<T>& v, int l, int r, Comp c, mt19937& rng) {
    uniform_int_distribution<int> d {l, r};
    swap(v[d(rng)], v[r]);
    return partition(v, l, r, c);
}

template void quick_sort(vector<int>& v, std::less<int> c);
template void quick_sort_randomized(vector<int>& v, std::less<int> c);
