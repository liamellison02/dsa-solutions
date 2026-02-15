/*
platform: lc
id: 72
name: edit distance
difficulty: hard
url: https://leetcode.com/problems/edit-distance/
pattern: dp/two_string
tags: dp,subsequence,bottom-up,string
complexity:
- time = O(m*n)
- space = O(n)
notes:
bottom-up dp
dp[i][j] = min operations to make w1[i:] == w2[j:]
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
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    if (m < n) {
      swap(m, n);
      swap(word1, word2);
    }

    vector<int> dp(n + 1), next(n + 1);
    for (int j{}; j <= n; ++j)
      dp[j] = n - j;

    for (int i = m - 1; i >= 0; --i) {
      next[n] = m - i;
      for (int j = n - 1; j >= 0; --j) {
        if (word1[i] == word2[j])
          next[j] = dp[j + 1];
        else
          next[j] = 1 + min(dp[j], min(next[j + 1], dp[j + 1]));
      }
      dp = next;
    }
    return dp[0];
  }
};
