/*
platform: lc
id: 152
name: maximum product subarray
pattern: dp/1d/kadanes
tags: kadanes,array,dp,1d-dp
complexity:
- time = O()
- space = O()
notes: use kadanes algorithm to track max and min product of any subarray ending
at i, traversing from i = 0 to nums.size()
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
using LL = long long;
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
  int maxProduct(vector<int> &nums) {
    int mx = nums[0], mn = nums[0], res = nums[0];

    for (int i{1}; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        mx = max(nums[i], nums[i] * mx);
        mn = min(mn, nums[i] * mn);
      } else if (nums[i] < 0) {
        int tmp = mx;
        mx = max(nums[i], nums[i] * mn);
        mn = min(nums[i], nums[i] * tmp);
      } else {
        mn = 0;
        mx = 0;
      }

      res = max(mx, res);
    }

    return res;
  }
};
