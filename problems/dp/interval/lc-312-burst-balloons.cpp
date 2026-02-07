/*
platform: lc
id: 312
name: burst balloons
pattern: dp/interval
tags: dp,2d-dp,bottom-up,interval-dp,intervals
complexity:
- time = O(n^3)
- space = O(n^2)
notes:
bottom-up solution:
DP[i][j] = max possible coins from interval [i...j]

for any interval [i...j] containing k:
if k is popped last, then the max possible coins in the interval
when popping k last is:
   nums[i-1] * k * nums[j+1] + DP[i:k-1] + DP[k+1:j]
do this for all k in the interval [i...j] to find max coins from the interval

**bottom-up can be tricky to order the interval iteration sequence**
to iterate over all intervals:
  - iterate through i=n...1, j=i...n

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
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    VI arr(n + 2, 1);
    for (int i{}; i < n; ++i)
      arr[i + 1] = nums[i];
    VVI DP(n + 2, VI(n + 2, 0));

    for (int i = n; i >= 1; --i) {
      for (int j = i; j <= n; ++j) {
        for (int k = i; k <= j; ++k) {
          DP[i][j] = max(DP[i][j], arr[i - 1] * arr[k] * arr[j + 1] +
                                       DP[i][k - 1] + DP[k + 1][j]);
        }
      }
    }
    return DP[1][n];
  }
};
