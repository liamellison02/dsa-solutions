/*
platform: cf
id: 2207C
name: wheres-my-water
url: https://codeforces.com/contest/2207/problem/C
pattern: dp/linear
tags: dp,greedy,prefix-sum,enumeration
complexity:
- time = O(n^2)
- space = O(n)
notes:
drain at col c captures h - max(a[c..j]) in column j (going left/right)
for 2 drains, optimal = max over split m of best_prefix[m] + best_suffix[m+1]
incrementally extend each drain's reach as prefix/suffix grows
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)
using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using Vll = vector<ll>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVll = vector<Vll>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;
template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;

static inline void solve() {
  int n;
  ll h;
  cin >> n >> h;
  Vll a(n + 1);
  FOR(i, 1, n + 1) cin >> a[i];

  Vll left_sum(n + 1, 0);
  FOR(c, 1, n + 1) {
    ll mx = 0;
    for (int j = c; j >= 1; j--) {
      mx = max(mx, a[j]);
      if (h > mx)
        left_sum[c] += h - mx;
    }
  }

  Vll right_sum(n + 1, 0);
  FOR(c, 1, n + 1) {
    ll mx = 0;
    FOR(j, c, n + 1) {
      mx = max(mx, a[j]);
      if (h > mx)
        right_sum[c] += h - mx;
    }
  }

  Vll P(n + 2, 0);
  Vll wv(n + 1, 0);
  Vll rmx(n + 1, 0);
  FOR(m, 1, n + 1) {
    rmx[m] = a[m];
    wv[m] = left_sum[m];
    ll best = wv[m];
    FOR(c, 1, m) {
      rmx[c] = max(rmx[c], a[m]);
      if (h > rmx[c])
        wv[c] += h - rmx[c];
      best = max(best, wv[c]);
    }
    P[m] = max(P[m - 1], best);
  }
  Vll S(n + 2, 0);
  Vll wv2(n + 2, 0);
  Vll lmx(n + 2, 0);
  for (int m = n; m >= 1; m--) {
    lmx[m] = a[m];
    wv2[m] = right_sum[m];
    ll best = wv2[m];
    FOR(c, m + 1, n + 1) {
      lmx[c] = max(lmx[c], a[m]);
      if (h > lmx[c])
        wv2[c] += h - lmx[c];
      best = max(best, wv2[c]);
    }
    S[m] = max(S[m + 1], best);
  }
  ll ans = 0;
  rep(m, n + 1) ans = max(ans, P[m] + S[m + 1]);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
