#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits.h>
#include <random>

#include "selection.h"

using namespace std;

int main() {
    random_device rand_device;
    mt19937 rand_engine(rand_device());
    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
    auto rng = [&dist, &rand_engine](){
        return dist(rand_engine);
    };

    int N;
    cout << "Enter the number of elements to generate: ";
    cin >> N;

    vector<int> data(N);
    generate(data.begin(), data.end(), rng);

    sort(data.begin(), data.end());

    for(int i=0; i<N; i++) {

        shuffle(data.begin(), data.end(), rand_engine);
        int my_nth = get_nth_element(data, i, less<int>());
        
        shuffle(data.begin(), data.end(), rand_engine);
        nth_element(data.begin(), data.begin() + i, data.end());
        int std_nth = data[i];

        assert(my_nth == std_nth);
    }

    cout << "TEST PASSED.\n";
}