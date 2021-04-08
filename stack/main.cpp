#include <iostream>

#include "stack.h"

using namespace std;

int main() {
    int N, x;
    Stack<int> stk;

    cout << "Enter the number of values you want to insert: ";
    cin >> N;

    while(N--) {
        cout << "Enter a value: ";
        cin >> x;
        stk.push(x);
    }

    cout << "Stack:\n";
    while(!stk.empty())
        cout << stk.pop() << "\n";
    
    return 0;
}