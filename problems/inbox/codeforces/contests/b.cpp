#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef long long ll;

void solution() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    FOR(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    ll k = min<ll>(n, m);
    ll ans = 0;
    FOR(i, 0, (int)k) {
        ans += a[i] * (m - i);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}