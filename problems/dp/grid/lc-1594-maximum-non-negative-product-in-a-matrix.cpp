/*
platform: lc
id: 1594
name: maximum non negative product in a matrix
pattern: dp/grid
tags: dp,bottom-up,grid-dp,grid,matrix
complexity:
- time = O(m * n)
- space = O(m * n)
notes:
classic bottom-up dp solution.
did the 2d and 1d optimized approaches.
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
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

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using ll = long long;
using ull = unsigned long long;
using str = string;
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;
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
using pll = pair<ll, ll>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

constexpr int MOD = 1e9 + 7;

class Solution {
public:
  int maxProductPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vec<vec<pll>> dp(m + 1, vec<pll>(n + 1, {LLONG_MIN, LLONG_MAX}));

    dp[0][1] = {1, 1};

    rep(row, m) {
      int i{row + 1};
      rep(col, n) {
        int j{col + 1};
        ll val{grid[row][col]};

        ll umax{dp[i - 1][j].first}, umin{dp[i - 1][j].second};
        ll lmax{dp[i][j - 1].first}, lmin{dp[i][j - 1].second};

        ll mx, mn;
        if (umax == LLONG_MIN) {
          mx = lmax;
          mn = lmin;
        } else if (lmax == LLONG_MIN) {
          mx = umax;
          mn = umin;
        } else {
          mx = max(umax, lmax);
          mn = min(umin, lmin);
        }

        if (val >= 0) {
          dp[i][j].first = val * mx;
          dp[i][j].second = val * mn;
        } else {
          dp[i][j].first = val * mn;
          dp[i][j].second = val * mx;
        }
      }
    }

    return dp[m][n].first >= 0 ? (int)(dp[m][n].first % MOD) : -1;
  }
  int maxProductPath1D(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vec<pll> dp(n);

    dp[0] = {grid[0][0], grid[0][0]};

    FOR(j, 1, n) {
      ll v{grid[0][j]};
      ll a{v * dp[j - 1].first}, b{v * dp[j - 1].second};
      dp[j] = {max(a, b), min(a, b)};
    }

    FOR(i, 1, m) {
      ll v{grid[i][0]};
      ll a{v * dp[0].first}, b{v * dp[0].second};
      dp[0] = {max(a, b), min(a, b)};

      FOR(j, 1, n) {
        v = grid[i][j];
        ll la{v * dp[j - 1].first}, lb{v * dp[j - 1].second};
        ll ua{v * dp[j].first}, ub{v * dp[j].second};
        dp[j] = {max({la, lb, ua, ub}), min({la, lb, ua, ub})};
      }
    }

    return dp[n - 1].first >= 0 ? (int)(dp[n - 1].first % MOD) : -1;
  }
};
