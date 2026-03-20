/*
platform: lc
id: 3567
name: minimum absolute difference in sliding submatrix
pattern: arrays/sorting
tags: sorting,matrix,enumeration,counting
complexity:
- time = O(m * n * (m-k+1) * (n-k+1))
- space = O((m-k+1) * (n-k+1))
notes:
iterate through all possible starting cells
for each starting point:
  - create a list of all cell values in the kxk submatrix
  - sort the values
  - add min abs diff to res
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
  vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    VVI res(m - k + 1, VI(n - k + 1, 0));

    rep(i, m - k + 1) {
      rep(j, n - k + 1) {
        VI sub;
        for (int r{i}; r < i + k && r < m; ++r)
          for (int c{j}; c < j + k && c < n; ++c)
            sub.push_back(grid[r][c]);

        sort(sub.begin(), sub.end());

        int md{INT_MAX};
        FOR(idx, 1, sub.size()) {
          if (sub[idx - 1] == sub[idx])
            continue;
          md = min(md, abs(sub[idx] - sub[idx - 1]));
        }

        if (md != INT_MAX)
          res[i][j] = md;
      }
    }

    return res;
  }
};
