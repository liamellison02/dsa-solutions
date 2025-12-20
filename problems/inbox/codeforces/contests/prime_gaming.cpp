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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef unsigned int uint;

const ll MOD = 1000000007LL;

int n, m, k;
vi good;
vvi opts;
vector<vc> dpa, dpb;

inline int erase_bit(int mask, int i) {
    int lo = mask & ((1 << (i - 1)) - 1);
    int hi = mask >> i;
    return lo | (hi << (i - 1));
}

char solve_a(int len, int mask);
char solve_b(int len, int mask);

char solve_a(int len, int mask) {
    if (len == 1) return (mask & 1) ? 1 : 0;
    char &memo = dpa[len][mask];
    if (memo != -1) return memo;
    for (int i : opts[len]) {
        int nmask = erase_bit(mask, i);
        if (solve_b(len - 1, nmask)) return memo = 1;
    }
    return memo = 0;
}

char solve_b(int len, int mask) {
    if (len == 1) return (mask & 1) ? 1 : 0;
    char &memo = dpb[len][mask];
    if (memo != -1) return memo;
    for (int i : opts[len]) {
        int nmask = erase_bit(mask, i);
        if (!solve_a(len - 1, nmask)) return memo = 0;
    }
    return memo = 1;
}

ll pw(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

vll fact, invfact;

ll C(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
}

ll lagrange_sum_k_pow_t(int t, ll x) {
    int d = t + 1;
    if ((ll)d >= x) {
        ll s = 0, cur = 1;
        for (ll i = 1; i <= x; i++) {
            cur = 1;
            for (int j = 0; j < t; j++) cur = (cur * i) % MOD;
            s += cur;
            if (s >= MOD) s -= MOD;
        }
        return s;
    }
    vll y(d + 1, 0);
    for (int i = 1; i <= d; i++) {
        ll p = 1;
        for (int j = 0; j < t; j++) p = (p * i) % MOD;
        y[i] = (y[i - 1] + p) % MOD;
    }
    vll pre(d + 2, 1), suf(d + 2, 1);
    for (int i = 0; i <= d; i++) pre[i + 1] = pre[i] * ((x - i) % MOD + MOD) % MOD;
    for (int i = d; i >= 0; i--) suf[i] = suf[i + 1] * ((x - i) % MOD + MOD) % MOD;
    ll ans = 0;
    for (int i = 0; i <= d; i++) {
        ll num = pre[i] * suf[i + 1] % MOD;
        ll denom = invfact[i] * invfact[d - i] % MOD;
        ll sign = ((d - i) & 1) ? MOD - 1 : 1;
        ll term = y[i] * num % MOD * denom % MOD * sign % MOD;
        ans += term;
        if (ans >= MOD) ans -= MOD;
    }
    return ans;
}

void solution() {
    cin >> n >> m;
    cin >> k;
    good.resize(k);
    FOR(i,0,k) cin >> good[i];

    opts.assign(n + 1, vi());
    sort(good.begin(), good.end());
    FOR(len,1,n+1) {
        for (int x : good) if (x <= len) opts[len].push_back(x);
    }

    dpa.assign(n + 1, vc());
    dpb.assign(n + 1, vc());
    FOR(len,0,n+1) {
        dpa[len].assign(1 << len, (char)-1);
        dpb[len].assign(1 << len, (char)-1);
    }

    vi gc(n + 1, 0);
    int total = 1 << n;
    FOR(mask,0,total) {
        if (solve_a(n, mask)) gc[__builtin_popcount((unsigned)mask)]++;
    }

    fact.assign(n + 2, 1);
    invfact.assign(n + 2, 1);
    FOR(i,1,n+2) fact[i] = fact[i-1] * i % MOD;
    invfact[n+1] = pw(fact[n+1], MOD - 2);
    for (int i = n; i >= 0; --i) invfact[i] = invfact[i+1] * (i + 1) % MOD;

    vll sp(n + 1, 0);
    FOR(t,0,n+1) sp[t] = lagrange_sum_k_pow_t(t, m);

    ll ans = 0;
    FOR(c,0,n+1) {
        int d = n - c;
        ll inner = 0;
        FOR(j,0,d+1) {
            ll term = C(d, j) * pw(m, d - j) % MOD;
            if (j & 1) term = (MOD - term) % MOD;
            term = term * sp[c + j] % MOD;
            inner += term;
            if (inner >= MOD) inner -= MOD;
        }
        ans = (ans + inner % MOD * gc[c]) % MOD;
    }

    cout << ans % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
