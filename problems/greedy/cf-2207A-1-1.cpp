/*
platform: cf
id: 2207A
name: 1-1
url: https://codeforces.com/contest/2207/problem/A
pattern: greedy
tags: greedy,simulation,binary-string
complexity:
- time = O(n)
- space = O(n)
notes:
groups of 1s separated by single 0s merge into super-groups.
max = fill entire super-group. min = floor(k/2)+1 (alternating).
runs of 2+ zeros are permanent barriers; s[1] and s[n] are fixed.
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
  int n;
  string s;
  cin >> n >> s;

  VPI groups;
  int i = 0;
  while (i < n) {
    if (s[i] == '1') {
      int j = i;
      while (j < n && s[j] == '1')
        j++;
      groups.push_back({i, j - 1});
      i = j;
    } else {
      i++;
    }
  }

  if (groups.empty()) {
    cout << "0 0\n";
    return;
  }

  VPI merged;
  merged.push_back(groups[0]);
  FOR(g, 1, (int)groups.size()) {
    auto &prev = merged.back();
    if (groups[g].first - prev.second == 2) {
      // single-0 gap → merge
      prev.second = groups[g].second;
    } else {
      merged.push_back(groups[g]);
    }
  }

  int mn = 0, mx = 0;
  for (auto &[l, r] : merged) {
    int k = r - l + 1;
    mx += k;
    mn += k / 2 + 1;
  }

  cout << mn << " " << mx << "\n";
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
