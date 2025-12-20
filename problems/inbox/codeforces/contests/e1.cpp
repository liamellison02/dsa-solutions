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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef unsigned int uint;

void solution() {
    int n, k;
    cin >> n >> k;
    vvi g(n + 1);
    FOR(i, 2, n + 1) {
        int p; cin >> p;
        g[p].push_back(i);
    }
    vi depth(n + 1, -1), order; order.reserve(n);
    depth[1] = 0; order.push_back(1);
    for (int idx = 0; idx < (int)order.size(); ++idx) {
        int u = order[idx];
        for (int v : g[u]) {
            depth[v] = depth[u] + 1;
            order.push_back(v);
        }
    }
    int min_depth = INT_MAX;
    FOR(u, 1, n + 1) if (g[u].empty()) min_depth = min(min_depth, depth[u]);
    int Lmax = min_depth + 1;
    vi width(Lmax, 0);
    FOR(u, 1, n + 1) if (depth[u] < Lmax) ++width[depth[u]];
    vc dp(n + 1, 0);
    dp[0] = 1;
    int sum = 0, ans = 0;
    FOR(d, 0, Lmax) {
        int w = width[d];
        sum += w;
        for (int s = sum; s >= w; --s) dp[s] = (dp[s] || dp[s - w]);
        int lo = max(0, sum - (n - k));
        int hi = min(k, sum);
        bool ok = false;
        for (int s = lo; s <= hi; ++s) if (dp[s]) { ok = true; break; }
        if (ok) ans = d + 1;
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
