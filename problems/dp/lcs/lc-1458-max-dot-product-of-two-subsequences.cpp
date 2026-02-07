/*
platform: lc
id: 1458
name: max dot product of two subsequences
pattern: dp/lcs
tags: dp,2d-dp,bottom-up,subsequence
complexity:
- time = O(m*n)
- space = O(m*n)
notes:
bottom-up dp solution
dp[i][j] = max dot product using suffixes nums1[i:] and nums2[j:]
intuition:
  at each pair, either
  a) match them (starting fresh if needed),
  b) skip one,
  c) skip the other,
  d) or skip both to find a better pairing.
transitions:
  - take = nums1[i]*nums2[j] + max(0, dp[i+1][j+1]),
  - skip_i = dp[i+1][j],
  - skip_j = dp[i][j+1].
base cases:
  - dp[m][*] = dp[*][n] = -inf (forces non-empty subsequence).
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
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    VVI DP(m + 1, VI(n + 1, INT_MIN / 2));

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int take = (nums1[i] * nums2[j]) + max(0, DP[i + 1][j + 1]);
        int skip_i = DP[i + 1][j];
        int skip_j = DP[i][j + 1];

        DP[i][j] = max({take, skip_i, skip_j});
      }
    }

    return DP[0][0];
  }
};
