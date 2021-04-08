#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <map>
#include <cassert>
#include <chrono>
#include <random>
#include <float.h>
#include <iomanip>

#include "insertion_sort/insertion_sort.h"
#include "merge_sort/merge_sort.h"
#include "quick_sort/quick_sort.h"

using namespace std;

void test_comparison_sorting_algorithms() {
    //random number generator setup
    random_device rand_device;
    mt19937 rand_engine(rand_device());
    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
    auto rng = [&dist, &rand_engine](){
        return dist(rand_engine);
    };

    int N;
    int iterations;

    cout << "Enter the number of times you want to repeat a test: ";
    cin >> iterations;
    cout << "The array will be generated randomly.\n";
    cout << "Enter the number of elements of the array: ";
    cin >> N;
    cout << "\n----------------------------------------------\n\n";

    vector<int> v(N);
    generate(v.begin(), v.end(), rng);

    map<string, function<void(vector<int>&, less<int>)>> functions = {
        { "Insertion sort", insertion_sort<int> },
        { "Merge sort", merge_sort<int> },
        { "Quick sort", quick_sort<int> },
        { "Quick sort randomized", quick_sort_randomized<int> }
    };

    double total_time, max_time, min_time, curr_time;
    for(auto &[name, sort_func] : functions) {
        max_time = total_time = 0.0f;
        min_time = DBL_MAX;

        for(int _ = 0; _ < iterations; _++) {
            shuffle(v.begin(), v.end(), rand_engine);

            auto start = chrono::steady_clock::now();
            sort_func(v, less<int>());
            auto end = chrono::steady_clock::now();

            assert(is_sorted(v.begin(), v.end()));
            
            chrono::duration<double> elapsed = end - start;
            curr_time = elapsed.count();

            max_time = max(max_time, curr_time);
            min_time = min(min_time, curr_time);
            total_time += curr_time;
        }

        cout << name << "\n";
        cout << "Total execution time: " << fixed << setprecision(12) << total_time << "s\n";
        cout << "Average execution time: " << fixed << setprecision(12) << total_time / (double) iterations << "s\n";
        cout << "Fastest: " << fixed << setprecision(12) << min_time << "s\n";
        cout << "Slowest: " << fixed << setprecision(12) << max_time << "s\n";
        cout << "\n\n";
    }
}

int main() {
    test_comparison_sorting_algorithms();    
}