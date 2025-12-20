#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<ll> A(n), B(m);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < m; ++i) cin >> B[i];

        sort(A.begin(), A.end(), greater<ll>());
        sort(B.begin(), B.end(), greater<ll>());

        vector<ll> prefA(n + 1, 0), prefB(m + 1, 0);
        for (int i = 1; i <= n; ++i) prefA[i] = prefA[i - 1] + A[i - 1];
        for (int i = 1; i <= m; ++i) prefB[i] = prefB[i - 1] + B[i - 1];

        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;

            int xa = min(x, n);
            int yb = min(y, m);
            int L = max(0, z - yb);
            int U = min(z, xa);

            if (L > U) { cout << 0 << "\n"; continue; }
            if (L == U) { cout << (prefA[L] + prefB[z - L]) << "\n"; continue; }

            int lo = L, hi = U;
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                ll a_next = (mid < n ? A[mid] : LLONG_MIN);
                int bj = z - mid - 1;
                ll b_drop = (bj >= 0 ? B[bj] : LLONG_MAX);
                if (a_next > b_drop) lo = mid + 1;
                else hi = mid;
            }
            int i_star = lo;
            ll ans = prefA[i_star] + prefB[z - i_star];
            cout << ans << "\n";
        }
    }
    return 0;
}
