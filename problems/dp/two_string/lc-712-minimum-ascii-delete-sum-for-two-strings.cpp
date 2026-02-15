/*
platform: lc
id: 712
name: minimum ascii delete sum for two strings
difficulty: medium
url: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
pattern: dp/two_string
tags: dp,subsequence,bottom-up,string
complexity:
- time = O(m*n)
- space = O(n)
notes:
bottom-up dp
dp[i][j] = min cost to make s1[i:] == s2[j:]
transitions:
a) if s1[i] == s2[j]:
  - dp[i][j] = dp[i+1][j+1]
b) else:
  - dp[i][j] = min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1])
base cases:
- dp[m][j] = sum(s2[j:])
- dp[i][n] = sum(s1[i:])
*/

#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
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
  int minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();

    vector<int> dp(n + 1, 0);
    for (int j = n - 1; j >= 0; --j)
      dp[j] = dp[j + 1] + s2[j];

    for (int i = m - 1; i >= 0; --i) {
      vector<int> next(n + 1, 0);
      next[n] = dp[n] + s1[i];

      for (int j = n - 1; j >= 0; --j) {
        if (s1[i] == s2[j])
          next[j] = dp[j + 1];
        else
          next[j] = min(s1[i] + dp[j], s2[j] + next[j + 1]);
      }
      dp = next;
    }
    return dp[0];
  }
};
