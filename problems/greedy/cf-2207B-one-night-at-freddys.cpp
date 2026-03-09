/*
platform: cf
id: 2207B
name: one-night-at-freddys
url: https://codeforces.com/contest/2207/problem/B
pattern: greedy
tags: greedy,minimax,simulation,sorting
complexity:
- time = O(l*m)
- space = O(m)
notes:
rem = number of flashlights not used yet/remaining
only k = min(m, rem + 1) animatronics are relevant
among relevant ones, animatronics should always add danger to a current minimum
at each flash, we should always reset current maximum
after using a flash, if k decreases, discard one current minimum relevant animatronic
summation of l over all test cases is <= 2e5 since m>=1 and sum(m*l) <= 2e5
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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
static inline void solve() {
  int n, m, l;
  cin >> n >> m >> l;
  VI a(n);
  rep(i, n) cin >> a[i];
  VI d(m, 0);
  int prev = 0;
  for (int interval = 0; interval <= n; ++interval) {
    int len;
    int k;
    if (interval < n) {
      len = a[interval] - prev;
      prev = a[interval];
      int remaining = n - interval;
      k = min(m, remaining + 1);
    } else {
      len = l - prev;
      k = 1;
    }
    for (int step = 0; step < len; ++step) {
      int pos = k - 1;
      int mn = d[pos];
      while (pos > 0 && d[pos - 1] == mn)
        --pos;
      ++d[pos];
      while (pos > 0 && d[pos] > d[pos - 1]) {
        swap(d[pos], d[pos - 1]);
        --pos;
      }
    }
    if (interval < n) {
      d[0] = 0;
      int pos = 0;
      while (pos + 1 < m && d[pos] < d[pos + 1]) {
        swap(d[pos], d[pos + 1]);
        ++pos;
      }
    }
  }
  cout << d[0] << '\n';
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
