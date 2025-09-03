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
