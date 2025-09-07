#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef long long ll;
typedef vector<int> vi;

void solution() {
    int n;
    if (!(cin >> n)) return;
    vi a(n + 1), b(n + 1);
    FOR(i, 1, n + 1) cin >> a[i];
    FOR(i, 1, n + 1) cin >> b[i];
    vi st_idx, st_val;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int ai = a[i], bi = b[i];
        while (!st_idx.empty() && st_val.back() < ai) {
            st_idx.pop_back();
            st_val.pop_back();
        }
        int pge = st_idx.empty() ? 0 : st_idx.back();
        int t = ai >= bi ? ai : bi;
        int pgeT = 0;
        if (!st_idx.empty()) {
            int lo = 0, hi = (int)st_val.size() - 1, pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (st_val[mid] >= t) { pos = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            if (pos != -1) pgeT = st_idx[pos];
        }
        int rec = (bi == ai) ? (i - pge) : 0;
        ans += (ll)(n - i + 1) * ( (ll)rec + (ll)pgeT );
        st_idx.push_back(i);
        st_val.push_back(ai);
    }
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
