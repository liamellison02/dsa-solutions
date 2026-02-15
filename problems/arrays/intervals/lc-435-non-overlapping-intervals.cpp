/*
platform: lc
id: 435
name: non overlapping intervals
difficulty: medium
url: https://leetcode.com/problems/non-overlapping-intervals/
pattern: arrays/intervals
tags: intervals,greedy,sorting
complexity:
- time = O(nlogn)
- space = O(1)
notes:
sort and then greedily remove the interval ending later when resolving two
overlapping intervals

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

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

    int res{0}, prev{-1000000};

    for (auto &in : intervals) {
      if (in[0] >= prev)
        prev = in[1];
      else {
        if (in[1] < prev)
          prev = in[1];
        ++res;
      }
    }

    return res;
  }
};
