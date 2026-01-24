/*
platform: lc
id: 10
name: regular expression matching
pattern: dp/interval
tags: dp,interval-dp,regex,2d-dp,string
complexity:
- time = O(m * n)
- space = O(m * n)
notes:
bottom-up dp:
dp[i][j] = can s[i:] be matched to p[j:]?

*/

#include <algorithm>
#include <map>
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

using VC = vector<char>;
using VVC = vector<VC>;

class Solution {
public:
  bool isMatchBottomUp(string s, string p) {
    int m = s.size(), n = p.size();
    VVC DP(m + 1, VC(n + 1, 0));
    DP[m][n] = 1;

    for (int i = m; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        bool match = i < m && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < n && p[j + 1] == '*')
          DP[i][j] = DP[i][j + 2] || (match && DP[i + 1][j]);
        else
          DP[i][j] = match && DP[i + 1][j + 1];
      }
    }

    return DP[0][0];
  }

  bool isMatchBottomUpOptimized(string s, string p) {
    int m = s.size(), n = p.size();
    VC dp(n + 1, 0), prev(n + 1, 0);
    prev[n] = 1;

    for (int i = m; i >= 0; --i) {
      dp[n] = (i == m);
      for (int j = n - 1; j >= 0; --j) {
        bool match = i < m && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < n && p[j + 1] == '*')
          dp[j] = dp[j + 2] || (match && prev[j]);
        else
          dp[j] = match && prev[j + 1];
      }
      swap(dp, prev);
    }
    return prev[0];
  }
};
