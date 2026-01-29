/*
platform: lc
id: 3651
name: minimum cost path with teleportations
pattern: dp/grid
tags: min-path,dp,grid-dp,bottom-up,prefix-sum,sorting
complexity:
- time = O(k*m*n)
- space = O(m*n)
notes:
find unique values in grid
sort unique
map each cell to it's associated idx in unique, then:

bottom-up DP.

k iterations
for each from t = 0...k:
DP[i][j] = min cost to get to cell (i,j);

transitions:
- normal moves:
a) moved right to (i,j) = dp[i-1][j] + grid[i][j]
b) moved down to (i,j) = dp[i][j-1] + grid[i][j]
- teleports:
c) min(dp[a][b] where grid[a][b] >= grid[i][j])

to prevent from m*n operations to calculate c) for all cells for all k layers,
you pre/suffixsum at each layer, based on the DP values in the previous layer,
and then map the suffix sum to each unique value.

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
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

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

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

class Solution {
public:
  int minCost(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    const int INF = 1e9;

    SI s;
    for (const auto &r : grid)
      s.insert(r.begin(), r.end());

    VI unique(s.begin(), s.end());
    int u = unique.size();

    VVI idx(m, VI(n));
    rep(i, m) rep(j, n) idx[i][j] =
        lower_bound(unique.begin(), unique.end(), grid[i][j]) - unique.begin();

    VVI dp(m, VI(n, INF));
    dp[0][0] = 0;

    // init layer
    rep(i, m) rep(j, n) {
      if (i > 0)
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
      if (j > 0)
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
    }

    // t = [1..k]
    FOR(t, 1, k + 1) {
      // PREVIOUS LAYER PRECOMPUTE WORK
      // find min tp costs at all unique vals
      VI v(u, INF);
      rep(i, m) rep(j, n) { v[idx[i][j]] = min(v[idx[i][j]], dp[i][j]); }
      // tp pre/suffixsummmmmssssss
      VI tp(u + 1, INF);
      rrep(i, u) tp[i] = min(v[i], tp[i + 1]);

      // CURRLAYER
      rep(i, m) rep(j, n) {
        dp[i][j] = min(dp[i][j], tp[idx[i][j]]);
        if (i > 0)
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
        if (j > 0)
          dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
      }
    }

    return dp[m - 1][n - 1];
  }
};
