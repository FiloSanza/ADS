#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

#include <vector>
#include <functional>
#include <random>

using namespace std;

template<typename T, typename Comp = std::less<T>>
void quick_sort(vector<T>& v, Comp c = Comp());

template<typename T, typename Comp>
void _quick_sort_rec(vector<T>& v, int l, int r, Comp c);

template<typename T, typename Comp>
int partition(vector<T>& v, int l, int r, Comp c);

template<typename T, typename Comp = std::less<T>>
void quick_sort_randomized(vector<T>& v, Comp c = Comp());

template<typename T, typename Comp>
void _quick_sort_randomized_rec(vector<T>& v, int l, int r, Comp c, mt19937& rng);

template<typename T, typename Comp>
int random_partition(vector<T>& v, int l, int r, Comp c, mt19937& rng);

#endif