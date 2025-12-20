#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

void solution() {
    int n;
    ll k;
    if (!(cin >> n >> k)) return;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vi cnt(n + 2, 0);
    FOR(i, 0, n) if (a[i] <= n) cnt[a[i]]++;
    int mex = 0;
    while (mex <= n && cnt[mex]) ++mex;
    ll sum_U = 0;
    int U = 0;
    int B = -1;
    for (int x = 0; x < mex; ++x) {
        if (cnt[x] == 1) { ++U; sum_U += x; }
        else if (cnt[x] >= 2 && B == -1) B = x;
    }
    if (k == 1) {
        ll ans = sum_U + 1LL * (n - U) * mex;
        cout << ans << '\n';
        return;
    }
    bool has_dup = (B != -1);
    if (!has_dup) B = mex;
    ll base = 1LL * B * (B - 1) / 2;
    int rem = n - B;
    if (rem <= 0) {
        cout << base << '\n';
        return;
    }
    if (rem == 1) {
        cout << base + B << '\n';
        return;
    }
    int block;
    if (has_dup) {
        block = B + ((k & 1) ? 1 : 0);
    } else {
        block = B + ((k % 2 == 0) ? 1 : 0);
    }
    ll ans = base + 1LL * rem * block;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
