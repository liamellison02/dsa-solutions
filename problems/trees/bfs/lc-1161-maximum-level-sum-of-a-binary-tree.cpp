/*
platform: lc
id: 1161
name: maximum level sum of a binary tree
difficulty: medium
url: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
pattern: trees/bfs
tags: bfs,tree,binary-tree
complexity:
- time = O(n)
- space = O(n)
notes: bfs for each level sum, return first level with the max level sum
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
using ll = long long;
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
  int maxLevelSum(TreeNode *root) {
    int ms = root->val, ml{0};

    vector<pair<TreeNode *, int>> q;
    vector<int> levels;

    q.push_back({root, 0});

    int i{0};
    while (i < q.size()) {
      auto [node, lvl] = q[i];

      if (lvl == levels.size())
        levels.push_back(node->val);
      else
        levels[lvl] += node->val;

      if (node->left)
        q.push_back({node->left, lvl + 1});
      if (node->right)
        q.push_back({node->right, lvl + 1});

      if (i + 1 < q.size() && q[i + 1].second > lvl && levels[lvl] > ms) {
        ms = levels[lvl];
        ml = lvl;
      }
      ++i;
    }

    int li = levels.size() - 1;
    return ms >= levels[li] ? ml + 1 : li + 1;
  }
};
