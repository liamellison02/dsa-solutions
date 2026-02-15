/*
platform: lc
id: 213
name: house robber II
difficulty: medium
url: https://leetcode.com/problems/house-robber-ii/
pattern: dp/linear
tags: dp,circular-array
complexity:
- time = O(n)
- space = O(1)
notes: treat circular street as two linear cases (skip first or skip last), run
rolling 1d dp for both in parallel and return the max
*/

#include <algorithm>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
using VPI = vector<PI>;
using VTI = vector<TI>;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();

    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);
    if (n == 3)
      return max(nums[1], max(nums[0], nums[2]));

    VI dp1(3, 0); // skip last
    VI dp2(3, 0); // skip first

    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);
    dp2[0] = nums[1];
    dp2[1] = max(nums[1], nums[2]);

    for (int i = 2, j = 3; i < n - 1; ++i, ++j) {
      dp1[2] = dp1[1];
      dp1[1] = max(nums[i] + dp1[0], dp1[1]);
      dp1[0] = dp1[2];

      dp2[2] = dp2[1];
      dp2[1] = max(nums[j] + dp2[0], dp2[1]);
      dp2[0] = dp2[2];
    }

    return max(dp1[1], dp2[1]);
  }
};
