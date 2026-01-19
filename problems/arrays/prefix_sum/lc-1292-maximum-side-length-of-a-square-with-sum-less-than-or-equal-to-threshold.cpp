/*
platform: lc
id: 1292
name: maximum side length of a square with sum less than or equal to threshold
pattern: arrays/prefix_sum
tags: prefix-sum,binary-search,array,matrix
complexity:
- time = O(m*n)
- space = O(m*n)
notes:
use prefix sums + inclusion-exclusion to calculate square sums.
start res at 0, then increment and check all possible square sums of len(res)
until none exist and return res.
*/

#include <algorithm>
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

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
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

class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    int m = mat.size(), n = mat[0].size();

    VVI pre(m + 1, VI(n + 1, 0));
    for (int i = 1; i < m + 1; ++i)
      for (int j = 1; j < n + 1; ++j)
        pre[i][j] = mat[i - 1][j - 1] + pre[i][j - 1] + pre[i - 1][j] -
                    pre[i - 1][j - 1];

    int res{};
    for (int i{1}; i <= m; ++i) {
      for (int j{1}; j <= n; ++j) {
        int k = res + 1;
        if (i >= k && j >= k) {
          int sum =
              pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
          if (sum <= threshold)
            res = k;
        }
      }
    }
    return res;
  }
};
