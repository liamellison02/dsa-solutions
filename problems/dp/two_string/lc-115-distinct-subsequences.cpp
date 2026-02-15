/*
platform: lc
id: 115
name: distinct subsequences
difficulty: hard
url: https://leetcode.com/problems/distinct-subsequences/
pattern: dp/two_string
tags: dp,subsequence,bottom-up,string
complexity:
- time = O(m*n)
- space = O(m*n) for first solution, O(n) for optimized
notes:
bottom-up dp
dp[i][j] = # ways to form t[j:] from s[i:]
transitions:
a) if s[i] == t[j]:
  - dp[i][j] = dp[i+1][j] + dp[i][j]
b) else:
  - dp[i][j] = dp[i+1][j] (defaults to prev char in s)
intuition:
at eash s[i], either skip or match with t[j] and advance both
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
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<ull>> DP(m + 1, vector<ull>(n + 1, 0));
    for (int i{}; i <= m; ++i)
      DP[i][n] = 1;

    for (int j = n - 1; j >= 0; --j) {
      for (int i = m - (n - j); i >= 0; --i) {
        DP[i][j] = DP[i + 1][j] + (s[i] == t[j] ? DP[i + 1][j + 1] : 0);
      }
    }

    return DP[0][0];
  }
};

class Solution2 {
public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<ull> DP(n + 1, 0);
    DP[n] = 1;

    for (int i = m - 1; i >= 0; --i) {
      for (int j{}; j < n; ++j) {
        if (s[i] == t[j])
          DP[j] += DP[j + 1];
      }
    }

    return DP[0];
  }
};
