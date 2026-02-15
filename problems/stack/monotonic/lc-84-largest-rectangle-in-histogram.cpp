/*
platform: lc
id: 84
name: largest rectangle in histogram
difficulty: hard
url: https://leetcode.com/problems/largest-rectangle-in-histogram/
pattern: stack/monotonic
tags: stack,array,monotonic-stack
complexity:
- time = O(n)
- space = O(n)
notes:
maintain stack of prev max heights in descending order.
while (currHeight < height at top of stk):
  pop previous max height from top of stk and calculate area
if currHeight > height at top of stack:
    push currHeight to stack
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
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size(), res{};
    stack<pair<int, int>> stk;

    for (int i{}; i < n; ++i) {
      int prev = i;
      while (!stk.empty() && heights[i] < stk.top().first) {
        auto &[h, j] = stk.top();
        res = max(res, (i - j) * h);
        prev = j;
        stk.pop();
      }
      if (stk.empty() || heights[i] > stk.top().first)
        stk.push({heights[i], prev});
    }

    while (!stk.empty()) {
      auto &[h, j] = stk.top();
      res = max(res, (n - j) * h);
      stk.pop();
    }

    return res;
  }
};
