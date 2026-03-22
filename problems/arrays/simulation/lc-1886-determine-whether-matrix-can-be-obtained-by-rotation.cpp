/*
platform: lc
id: 1886
name: determine whether matrix can be obtained by rotation
pattern: arrays/simulation
tags: simulation,matrix,rotation
complexity:
- time = O(n*n)
- space = O(1)
notes:
go through all 4 possible orientations w/ two-pointer "spiral matrix" check
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
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    int n = target.size();

    // 0° rotation
    int invalid{0};
    rep(i, n) {
      if (invalid)
        break;
      rep(j, n) {
        if (mat[i][j] != target[i][j]) {
          invalid = 1;
          break;
        }
      }
    }
    if (!invalid)
      return true;

    // 90° rotation
    invalid = 0;
    int lb{0}, ub{n - 1};

    while (lb <= ub) {
      // top of mat == right of target
      for (int i{lb}; i <= ub; ++i) {
        if (mat[lb][i] != target[i][ub]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // right of mat == bottom of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[i][ub] != target[ub][j]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // bottom of mat == left of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[ub][j] != target[j][lb]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // left of mat == top of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[j][lb] != target[lb][i]) {
          invalid = 1;
          break;
        }
      }
      ++lb;
      --ub;
    }
    if (!invalid)
      return true;

    // 180° rotation
    invalid = 0;
    lb = 0;
    ub = n - 1;
    while (lb <= ub) {
      // top of mat == bottom of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[lb][i] != target[ub][j]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // right of mat == left of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[i][ub] != target[j][lb]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // bottom of mat == top of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[ub][j] != target[lb][i]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // left of mat == right of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[j][lb] != target[i][ub]) {
          invalid = 1;
          break;
        }
      }
      ++lb;
      --ub;
    }
    if (!invalid)
      return true;

    // 270° rotation
    invalid = 0;
    lb = 0;
    ub = n - 1;
    while (lb <= ub) {
      // top of mat == left of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[lb][i] != target[j][lb]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // right of mat == top of target
      for (int i{lb}; i <= ub; ++i) {
        if (mat[i][ub] != target[lb][i]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // bottom of mat == right of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[ub][j] != target[i][ub]) {
          invalid = 1;
          break;
        }
      }
      if (invalid)
        break;

      // left of mat == bottom of target
      for (int i{lb}, j{ub}; i <= ub && j >= lb; ++i, --j) {
        if (mat[j][lb] != target[ub][j]) {
          invalid = 1;
          break;
        }
      }
      ++lb;
      --ub;
    }
    if (!invalid)
      return true;

    return false;
  }
};
