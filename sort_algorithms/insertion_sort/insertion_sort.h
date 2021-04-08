#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED

#include <vector>
#include <functional>

using namespace std;

template<typename T, typename Comp = std::less<T>>
void insertion_sort(vector<T>& v, Comp c = Comp());

#endif