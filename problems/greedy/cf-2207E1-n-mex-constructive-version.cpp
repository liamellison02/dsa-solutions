/*
platform: cf
id: 2207E1
name: n-mex-constructive-version
url: https://codeforces.com/contest/2207/problem/E1
pattern: greedy
tags: greedy,constructive,set,mex
complexity:
- time = O(n*log(n))
- space = O(n)
notes:
sequence a must be non-increasing for a valid construction to exist
a[0] must be n or n-1. when a[i] < a[i-1], value a[i] is "preserved" (placed as the boundary element)
otherwise pick the largest available free value
validate that mex condition holds at each prefix boundary
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
  cin >> n;
  VI a(n);
  rep(i, n) cin >> a[i];
  rep(i, n - 1) {
    if (a[i] < a[i + 1]) {
      cout << "NO\n";
      return;
    }
  }
  if (a[0] != n && a[0] != n - 1) {
    cout << "NO\n";
    return;
  }
  SI preserve;
  FOR(i, 1, n) {
    if (a[i] < a[i - 1])
      preserve.insert(a[i]);
  }
  VI b(n);
  SI avail;
  SI free_set;
  if (a[0] == n) {
    rep(j, n) avail.insert(j);
  } else {
    rep(j, n - 1) avail.insert(j);
  }
  for (int v : avail) {
    if (!preserve.count(v))
      free_set.insert(v);
  }
  rep(i, n) {
    if (i > 0 && a[i] < a[i - 1]) {
      auto it = avail.upper_bound(a[i]);
      if (it != avail.end()) {
        cout << "NO\n";
        return;
      }
      if (!avail.count(a[i])) {
        cout << "NO\n";
        return;
      }
      avail.erase(a[i]);
      preserve.erase(a[i]);
      b[i] = a[i - 1];
    } else if (i == 0 && a[0] == n - 1) {
      b[0] = n;
    } else {
      if (free_set.empty()) {
        cout << "NO\n";
        return;
      }
      int pick = *free_set.rbegin();
      free_set.erase(pick);
      avail.erase(pick);
      b[i] = pick;
    }
  }
  cout << "YES\n";
  rep(i, n) cout << b[i] << " \n"[i == n - 1];
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
