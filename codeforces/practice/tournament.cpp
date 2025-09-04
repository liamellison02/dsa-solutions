#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vvi matches(n+1, vi(n+1, 0));
    vi wins(n+1);

    int t = n*(n-1)/2-1;

    while (t--) {
        int x, y;
        cin >> x >> y;
        wins[x]++;
        matches[x][y]++;
        matches[y][x]++;
    }

    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            if (matches[i][j] == 0 && i != j) {
                (wins[i] > wins[j]) ? (cout << i << ' ' << j << '\n') : (cout << j << ' ' << i << '\n');
                return 0;
            }
        }
    }
}
