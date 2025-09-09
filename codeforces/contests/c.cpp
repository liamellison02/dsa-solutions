#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef unsigned int uint;

void solution() {
    ll k;
    ull x;
    cin >> k >> x;

    ull T = 1ULL << (k + 1);
    ull a = x, b = T - x;

    vi ops;
    while (a != b) {
        if (a > b) {
            ops.push_back(2);
            a = a - b;
            b = b << 1;
        } else {
            ops.push_back(1);
            b = b - a;
            a = a << 1;
        }
    }

    int n = (int)ops.size();
    cout << n << "\n";
    if (n > 0) {
        for (int i = n - 1; i >= 0; --i) {
            cout << ops[i] << (i ? ' ' : '\n');
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
