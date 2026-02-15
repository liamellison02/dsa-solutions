/*
platform: cf
id: 2193D
name: monster game
url: https://codeforces.com/problemset/problem/2193/D
pattern: binary_search/on_array
tags: prefix-sum,sorting,binary-search,greedy
complexity:
notes:
sort the swords and build prefix sum array for lvl costs.
then do binary search on prefix sum arr for each sword to find find max
clearable lvls w/ curr sword.
return max score found for each sword strength in swords as the difficulty.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

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
  cin >> n;
  Vll s(n);
  Vll l(n);
  for (int i{0}; i < n; ++i)
    cin >> s[i];
  for (int i{0}; i < n; ++i)
    cin >> l[i];

  sort(s.begin(), s.end());

  Vll pre(n + 1);
  for (int i{}; i < n; ++i)
    pre[i + 1] = pre[i] + l[i];

  ll res{0};
  for (int i{0}; i < n; ++i) {
    ll swords = n - i;

    int lvl = upper_bound(pre.begin(), pre.end(), swords) - pre.begin() - 1;

    if ((s[i] * lvl) > res)
      res = s[i] * lvl;
  }

  cout << res << '\n';
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
