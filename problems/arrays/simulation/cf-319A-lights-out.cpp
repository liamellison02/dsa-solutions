/*
platform: cf
id: 319A
name: lights-out
url: https://codeforces.com/problemset/problem/319/A
pattern: arrays/simulation
tags: simulation,grid,matrix
complexity:
- time = O(1)
- space = O(1)
notes: check 3x3 grid for lights out pattern
*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef vector<string> vs;

int main() {
    vs grid(4);
    int i, j;
    FOR (i, 0, 4) cin >> grid[i];
    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            int b = (grid[i][j] == '#') + (grid[i][j+1] == '#') + (grid[i+1][j] == '#') + (grid[i+1][j+1] == '#');
            if (b != 2) { cout << "YES" << '\n'; return 0; }
        }
    }
    cout << "NO" << "\n";
    return 0;
}
