/*
platform: lc
id: 97
name: interleaving string
difficulty: medium
url: https://leetcode.com/problems/interleaving-string/
pattern: dp/two_string
tags: dp,bottom-up,2d-dp,interval,string
complexity:
- time = O(n*m)
- space = O(min(n,m)) for version 1, O(m*n) for version 2

notes:
(solution 1 is the space optimized version of solution s2)
bottom-up dp:
- dp[i][j] indicates whether s3[i+j:] can be formed by interleaving s1[i:] and
s2[j:]
transitions:
dp[i][j] is true if
a) (s1[i] == s3[i+j] and dp[i+1][j]) or
b) (s2[j] == s3[i+j] and dp[i][j+1])
base case:
dp[sz1][sz2] = true (both strings consumed)

intuition: at each position, choose whether the next character of s3 comes from
s1 or s2
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
  bool isInterleave(string s1, string s2, string s3) {
    int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();
    if (sz1 + sz2 != sz3)
      return false;

    if (sz1 < sz2) {
      swap(s1, s2);
      swap(sz1, sz2);
    }

    vector<bool> DP(sz2 + 1, false);
    DP[sz2] = true;

    // base case
    for (int j = sz2 - 1; j >= 0; --j)
      DP[j] = (s2[j] == s3[sz1 + j]) && DP[j + 1];

    for (int i = sz1 - 1; i >= 0; --i) {
      DP[sz2] = (s1[i] == s3[i + sz2]) && DP[sz2];

      for (int j = sz2 - 1; j >= 0; --j) {
        bool take1 = (s1[i] == s3[i + j]) && DP[j];
        bool take2 = (s2[j] == s3[i + j]) && DP[j + 1];
        DP[j] = take1 || take2;
      }
    }

    return DP[0];
  }

  bool isInterleave2(string s1, string s2, string s3) {
    int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();
    if (sz1 + sz2 != sz3)
      return false;

    vector<vector<char>> DP(sz1 + 1, vector<char>(sz2 + 1, 0));
    DP[sz1][sz2] = 1;

    int i1 = sz1 - 1;
    int i2 = sz2 - 1;

    for (int i1 = sz1; i1 >= 0; --i1) {
      for (int i2 = sz2; i2 >= 0; --i2) {
        if (i1 < sz1 && s1[i1] == s3[i1 + i2] && DP[i1 + 1][i2])
          DP[i1][i2] = 1;
        if (i2 < sz2 && s2[i2] == s3[i1 + i2] && DP[i1][i2 + 1])
          DP[i1][i2] = 1;
      }
    }

    return DP[0][0] ? true : false;
  }
};
