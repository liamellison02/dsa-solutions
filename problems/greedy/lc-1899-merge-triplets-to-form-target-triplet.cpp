/*
platform: lc
id: 1899
name: merge triplets to form target triplet
difficulty: medium
url: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
pattern: greedy
tags: greedy,array
complexity:
- time = O(n)
- space = O(1)
notes:
i mean just read the solution and think about it lol.
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
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    int res[3] = {0, 0, 0};

    for (auto &t : triplets) {
      if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
        if (t[0] > res[0])
          res[0] = t[0];
        if (t[1] > res[1])
          res[1] = t[1];
        if (t[2] > res[2])
          res[2] = t[2];
      }
    }

    return (res[0] == target[0] && res[1] == target[1] && res[2] == target[2])
               ? true
               : false;
  }
};
