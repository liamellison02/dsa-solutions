/*
platform: lc
id: 763
name: partition labels
difficulty: medium
url: https://leetcode.com/problems/partition-labels/
pattern: greedy
tags: greedy,intervals,two-pointers,string,sorting,hashing
complexity:
- time = O(n)
- space = O(1)
notes:
iterate two times.

first iteration:
track last idx of each unique char in array

second iteration:
use two pointers to build each interval
cutoff point for an interval:
- if last idx of all chars in interval == current idx
*/

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
  vector<int> partitionLabels(string s) {
    int n = s.size();

    VI last(26, -1);
    for (int i{}; i < n; ++i)
      last[s[i] - 'a'] = i;

    VI res;
    int l{}, r{};
    for (int i{}; i < n; ++i) {
      if (last[s[i] - 'a'] > r)
        r = last[s[i] - 'a'];
      if (r == i) {
        res.push_back(r - l + 1);
        l = i + 1;
        r = i + 1;
      }
    }
    return res;
  }
};
