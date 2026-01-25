/*
platform: lc
id: 45
name: jump game II
pattern: dp/1D
tags: dp,greedy,bfs,two-pointers
complexity:
- time = O(n)
- space = O(1)
notes: greedy bfs approach, using left and right bounds per level until OOB
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
  int jump(vector<int> &nums) {
    int n = nums.size(), l = 0, r = 0, lvl = 0;
    while (r < n - 1) {
      int furthest = r;
      for (int i = l; i <= r; ++i)
        furthest = max(nums[i] + i, furthest);
      l = r + 1;
      r = furthest;
      ++lvl;
    }
    return lvl;
  }
};
