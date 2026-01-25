/*
platform: lc
id: 56
name: merge intervals
pattern: arrays/intervals
tags: intervals,arrays,sorting
complexity:
- time = O(nlogn)
- space = O(n)
notes:
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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {

    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

    int i = 0;
    for (auto &in : intervals) {
      if (i == 0 || in[0] > intervals[i - 1][1]) {
        intervals[i] = in;
        i++;
      } else
        intervals[i - 1][1] = max(intervals[i - 1][1], in[1]);
    }

    intervals.resize(i);
    return intervals;
  }
};
