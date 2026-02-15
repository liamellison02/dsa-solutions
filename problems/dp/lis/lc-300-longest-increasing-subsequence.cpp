/*
platform: lc
id: 300
name: longest increasing subsequence
difficulty: medium
url: https://leetcode.com/problems/longest-increasing-subsequence/
pattern: dp/lis
tags: dp,bottom-up
complexity:
- time = O(n^2)
- space = O(n)
notes: bottom-up dp starting at last num.
iterate backwards, checking all dp vals for nums prior to curr num
update curr num's dp val to max value found when iterating through prev nums
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

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size(), res{1};
    VI dp(n, 1);

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j)
        if (nums[i] < nums[j] && dp[i] <= dp[j])
          dp[i] = 1 + dp[j];
      if (dp[i] > res)
        res = dp[i];
    }

    return res;
  }
};
