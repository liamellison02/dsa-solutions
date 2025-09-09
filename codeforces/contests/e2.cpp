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

static inline void push_subset(vector<ull>& bs, int add, int words, int bitcap) {
    if (add <= 0) return;
    int cap = bitcap - 1;
    if (add > cap) return;
    int w = add >> 6, b = add & 63;
    for (int i = words - 1; i >= 0; --i) {
        ull x = 0ULL;
        int from = i - w;
        if (from >= 0) {
            x = bs[from] << b;
            if (b && (from - 1) >= 0) x |= bs[from - 1] >> (64 - b);
        }
        bs[i] |= x;
    }
    int rem = bitcap & 63;
    if (rem) {
        ull mask = (1ULL << rem) - 1ULL;
        bs[words - 1] &= mask;
    }
}

static inline bool has_any(const vector<ull>& bs, int L, int R) {
    if (L > R) return false;
    int total_bits = (int)bs.size() * 64;
    if (L < 0) L = 0;
    if (R >= total_bits) R = total_bits - 1;
    int wi = L >> 6, bi = L & 63;
    int wj = R >> 6, bj = R & 63;
    if (wi == wj) {
        ull left = (~0ULL) << bi;
        ull right = (bj == 63 ? ~0ULL : ((1ULL << (bj + 1)) - 1ULL));
        return (bs[wi] & (left & right)) != 0ULL;
    }
    if ((bs[wi] & (~0ULL << bi)) != 0ULL) return true;
    for (int k = wi + 1; k <= wj - 1; ++k) if (bs[k]) return true;
    ull right = (bj == 63 ? ~0ULL : ((1ULL << (bj + 1)) - 1ULL));
    return (bs[wj] & right) != 0ULL;
}

void solution() {
    int n, k;
    cin >> n >> k;

    vvi children(n + 1);
    FOR(i, 2, n + 1) {
        int p; cin >> p;
        children[p].push_back(i);
    }

    vi depth(n + 1, -1), order; order.reserve(n);
    depth[1] = 0; order.push_back(1);
    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int v : children[u]) {
            depth[v] = depth[u] + 1;
            order.push_back(v);
        }
    }

    int min_leaf_depth = INT_MAX;
    FOR(u, 1, n + 1) if (children[u].empty()) min_leaf_depth = min(min_leaf_depth, depth[u]);

    int layers = min_leaf_depth + 1;
    vi layer_size(layers, 0);
    FOR(u, 1, n + 1) if (depth[u] < layers) ++layer_size[depth[u]];

    ll zeros = k, ones = n - k;
    ll small_cap = min(zeros, ones), big_cap = max(zeros, ones);

    int C = (int)small_cap;
    int bitcap = C + 1, words = (bitcap + 63) / 64;

    vector<ull> bs(words, 0ULL);
    bs[0] = 1ULL;

    ll prefix = 0;
    int best = 0;

    FOR(d, 0, layers) {
        int w = layer_size[d];
        push_subset(bs, w, words, bitcap);
        prefix += w;
        ll L = prefix - big_cap;
        if (L < 0) L = 0;
        if (L <= C && has_any(bs, (int)L, C)) best = d + 1;
    }

    cout << best << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
