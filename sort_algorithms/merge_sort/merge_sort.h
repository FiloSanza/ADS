#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

#include <vector>
#include <functional>

using namespace std;

template<typename T, typename Comp = std::less<T>>
void merge_sort(vector<T>& v, Comp c = Comp());

template<typename T, typename Comp>
void _merge_sort_rec(vector<T>& v, size_t l, size_t r, Comp c, vector<int>& buffer);

template<typename T>
void _merge_sort_merge(vector<T>& v, size_t l, size_t mid, size_t r, vector<int>& buffer);

#endif