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
typedef vector<ll> vll;

void solution() {
    int n;
    cin >> n;
    vll a(n + 1);
    FOR(i, 1, n + 1) cin >> a[i];

    ll s = 0;
    FOR(i, 1, n + 1) s += (i & 1) ? a[i] : -a[i];

    ll best_same = 0;
    if (n >= 2) best_same = (n & 1) ? (n - 1) : (n - 2);

    const ll neg_inf = LLONG_MIN / 4;
    vll odd_pref(n + 2, neg_inf), odd_suff(n + 3, neg_inf);
    FOR(i, 1, n + 1) {
        odd_pref[i] = odd_pref[i - 1];
        if (i & 1) odd_pref[i] = max(odd_pref[i], - (ll)i - 2LL * a[i]);
    }
    for (int i = n; i >= 1; --i) {
        odd_suff[i] = odd_suff[i + 1];
        if (i & 1) odd_suff[i] = max(odd_suff[i], (ll)i - 2LL * a[i]);
    }

    ll best_cross = neg_inf;
    for (int e = 2; e <= n; e += 2) {
        ll cand = neg_inf;
        if (odd_pref[e - 1] != neg_inf) cand = max(cand, (ll)e + odd_pref[e - 1]);
        if (odd_suff[e + 1] != neg_inf) cand = max(cand, - (ll)e + odd_suff[e + 1]);
        if (cand != neg_inf) best_cross = max(best_cross, 2LL * a[e] + cand);
    }

    ll add = 0;
    add = max(add, best_same);
    if (best_cross != neg_inf) add = max(add, best_cross);

    cout << s + add << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
