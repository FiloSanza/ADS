#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

#include <vector>
#include <functional>
#include <math.h>

using namespace std;

template<typename T, typename Comp = less<T>>
T get_nth_element(vector<T>& v, size_t nth, Comp c = Comp());

template<typename T, typename Comp = less<T>>
T _get_nth_element(vector<T>& v, size_t l, size_t r, size_t nth, Comp c = Comp());

template<typename T, typename Comp = less<T>>
int _partition(vector<T>& v, int l, int r, T key, Comp c);

#endif