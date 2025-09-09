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

void solution() {
    ll a, b;
    cin >> a >> b;
    if (a == b) { cout << 0 << "\n"; return; }
    ll mx = max(a, b), mn = min(a, b);
    cout << (mx % mn == 0 ? 1 : 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}