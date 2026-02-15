/*
platform: lc
id: 1984
name: minimum difference between highest and lowest of k scores
difficulty: medium
url: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
pattern: sliding_window
tags: sorting,sliding-window,array
complexity:
- time = O(nlogn)
- space = O(1)
notes:
just think abt it lol
*/

#include <algorithm>
#include <climits>
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

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int res{INT_MAX};
    for (int i{}, j{k - 1}; j < nums.size(); ++i, ++j)
      if (nums[j] - nums[i] < res)
        res = nums[j] - nums[i];
    return res;
  }
};
