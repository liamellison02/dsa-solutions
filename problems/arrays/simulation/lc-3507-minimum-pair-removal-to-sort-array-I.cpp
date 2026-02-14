/*
platform: lc
id: 3507
name: minimum pair removal to sort array I
pattern: arrays/simulation
tags: array,simulation,sorting
complexity:
- time = O(n^2)
- space = O(1)
notes:
essentially just a sorting algorithm where you can replace smallest pair of
elements w/ their sum
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int ops{};

    while (nums.size() > 1) {
      int ms = INT_MAX, mi{-1};
      bool srtd{true};

      for (int i{1}; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1])
          srtd = false;
        if (nums[i] + nums[i - 1] < ms) {
          ms = nums[i] + nums[i - 1];
          mi = i - 1;
        }
      }

      if (srtd)
        return ops;

      nums[mi] = ms;
      nums.erase(nums.begin() + mi + 1);
      ++ops;
    }

    return ops;
  }
};
