/*
platform: lc
id: 2906
name: construct product matrix
pattern: arrays/prefix_sum
tags: prefix-sum,simulation,modulo,grid,matrix
complexity:
- time = O(m * n)
- space = O(1)
notes:
use prefix + suffix sums (products).
note that we don't count output arr as additional space.
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

constexpr int MOD = 1e9 + 7;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using str = string;

using ll = long long;
using ull = unsigned long long;
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ti = tuple<int, int, int>;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vpi = vector<pi>;
using vti = vector<ti>;
using vvc = vector<vc>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvs = vector<vs>;
using vvpi = vector<vpi>;

using si = set<int>;
using usi = unordered_set<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;

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

class Solution {
public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vvi p(m, vi(n, 0));

    int curr{1};
    rrep(i, m) {
      rrep(j, n) {
        p[i][j] = curr;
        curr = (ll)curr * grid[i][j] % MOD;
      }
    }

    curr = 1;
    rep(i, m) {
      rep(j, n) {
        p[i][j] = (ll)p[i][j] * curr % MOD;
        curr = (ll)grid[i][j] * curr % MOD;
      }
    }

    return p;
  }
};
