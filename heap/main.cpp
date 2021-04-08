#include <queue>
#include <random>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <cassert>

#include "heap.h"

using namespace std;

void test_build_heap(int N, vector<int>& in) {
    cout << "TEST BUILD HEAP\n";

    vector<int> out;
    Heap<int, less<int>> heap(in);

    while(!heap.empty())
        out.push_back(heap.pop());


    sort(in.begin(), in.end());
    for(int i=0; i<N; i++)
        assert(in[i] == out[i]);

    cout << "OK.\n";
}

void test_insert(int N, vector<int>& in) {
    cout << "TEST INSERT\n";

    vector<int> out;
    Heap<int, less<int>> heap;

    for(auto i : in) heap.insert(i);

    while(!heap.empty())
        out.push_back(heap.pop());


    sort(in.begin(), in.end());
    for(int i=0; i<N; i++)
        assert(in[i] == out[i]);

    cout << "OK.\n";
}

int main() {
    random_device rand_device;
    mt19937 rand_engine(rand_device());
    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
    auto rng = [&dist, &rand_engine](){
        return dist(rand_engine);
    };

    int N;

    cout << "The array will be generated randomly.\n";
    cout << "Enter the number of elements of the array: ";
    cin >> N;
    cout << "\n----------------------------------------------\n\n";

    vector<int> in(N);
    generate(in.begin(), in.end(), rng);

    test_build_heap(N, in);
    cout << "\n----------------------------------------------\n\n";

    shuffle(in.begin(), in.end(), rand_engine);
    test_insert(N, in);

    return 0;
}