/*
platform: lc
id: 57
name: insert interval
difficulty: medium
url: https://leetcode.com/problems/insert-interval/
pattern: arrays/intervals
tags: intervals,array
complexity:
- time = O(n)
- space = O(n)
notes: iterate and merge overlap into new interval; once past merging, append
remainder
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
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    VVI res;
    int n = intervals.size(), start = newInterval[0], end = newInterval[1];

    for (int i{}; i < n; ++i) {
      if (intervals[i][0] > end) {
        res.push_back(newInterval);
        copy(intervals.begin() + i, intervals.end(), back_inserter(res));
        return res;
      } else if (intervals[i][1] < start)
        res.push_back(intervals[i]);
      else {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
      }
    }
    res.push_back(newInterval);
    return res;
  }
};
