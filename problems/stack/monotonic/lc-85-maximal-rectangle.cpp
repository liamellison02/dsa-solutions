/*
platform: lc
id: 85
name: maximal rectangle
difficulty: hard
url: https://leetcode.com/problems/maximal-rectangle/
pattern: stack/monotonic
tags: stack,matrix,monotonic-stack,dp
complexity:
- time = O(m*n)
- space = O(n)
notes:
for each row i, maintain a "histogram" of heights where:
heights[j] = length of continuous 1's starting at cell j in row i
then, run "largest rect in histogram" for each row.
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
using VC = vector<char>;
using VI = vector<int>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVS = vector<VS>;
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
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size(), res{};
    vector<int> heights(n, 0);

    for (int i{}; i < m; ++i) {

      for (int j{}; j < n; ++j) {
        if (matrix[i][j] == '1')
          ++heights[j];
        else
          heights[j] = 0;
      }

      res = max(res, maxArea(heights, n));
    }

    return res;
  }

private:
  int maxArea(vector<int> ht, const int &n) {
    stack<pair<int, int>> stk;
    int res{};

    for (int i{}; i < n; ++i) {
      int prev = i;
      while (!stk.empty() && ht[i] < stk.top().first) {
        auto &[h, j] = stk.top();
        res = max(res, h * (i - j));
        prev = j;
        stk.pop();
      }
      if (stk.empty() || ht[i] > stk.top().first)
        stk.push({ht[i], prev});
    }

    while (!stk.empty()) {
      auto &[h, j] = stk.top();
      res = max(res, h * (n - j));
      stk.pop();
    }

    return res;
  }
};
