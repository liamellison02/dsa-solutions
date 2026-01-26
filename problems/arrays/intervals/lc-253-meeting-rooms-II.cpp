/*
platform: lc
id: 253
name: meeting rooms II
pattern: arrays/intervals
tags: intervals,greedy,sorting
complexity:
- time = O(nlogn)
- space = O(n)
notes:
convert start and end times to separate events and then sort these events.
iterate through the events, keeping track of total meetings at any given time.
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
  int minMeetingRooms(vector<vector<int>> &intervals) {
    vector<pair<int, int>> t;
    for (const auto &in : intervals) {
      t.push_back({in[0], 1});
      t.push_back({in[1], -1});
    }

    sort(t.begin(), t.end(), [](auto &a, auto &b) {
      return a.first == b.first ? a.second < b.second : a.first < b.first;
    });

    int res{0}, cnt{0};
    for (const auto &e : t) {
      cnt += e.second;
      res = max(res, cnt);
    }

    return res;
  }
};
