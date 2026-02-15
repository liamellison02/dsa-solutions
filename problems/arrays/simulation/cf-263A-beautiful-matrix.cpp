/*
platform: cf
id: 263A
name: beautiful-matrix
url: https://codeforces.com/problemset/problem/263/A
pattern: arrays/simulation
tags: simulation,matrix
complexity:
- time = O(1)
- space = O(1)
notes: manhattan distance to center
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r = -1, c = -1, x;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> x;
            if (x==1) {r = i; c = j; }
        }
    }
    cout << abs(r-3) + abs(c-3) << '\n';
    return 0;
}
