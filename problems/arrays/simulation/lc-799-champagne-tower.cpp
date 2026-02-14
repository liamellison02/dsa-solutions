/*
platform: lc
id: 799
name: champagne tower
pattern: arrays/simulation
tags: simulation,triangle,overflow,math
complexity:
- time = O(5050) = O(1)
- space = O(5050) = O(1)
notes:
simluate the overflow at each row; stop at query_row.

algorithm:
start by setting tower[0][0] to poured - 1 (overflow).
- for each row i = [0..100]:
  - for each glass j = [0..i], do either:
    a) if it has overflow (tower[i][j] > 1):
      - set tower[i+1][j] = overflow / 2
      - set tower[i+1][j+1] = overflow / 2
    b) otherwise, do nothing.

return tower[query_row][query_glass]

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

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    double tower[100][100]{};
    tower[0][0] = poured;

    rep(i, 99) {
      if (i == query_row)
        return tower[query_row][query_glass] > 1.0
                   ? 1.0
                   : tower[query_row][query_glass];

      // populate the glasses in the next row from curr row overflow
      FOR(j, 0, i + 1) {
        if (tower[i][j] > 1) {
          double over = (tower[i][j] - 1) / 2;
          tower[i + 1][j] += over;
          tower[i + 1][j + 1] += over;
        }
      }
    }
    return tower[query_row][query_glass] > 1.0 ? 1.0
                                               : tower[query_row][query_glass];
  }
};
