/*
platform: lc
id: 1123
name: lowest common ancestor of deepest leaves
difficulty: medium
url: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
pattern: trees/lca
tags: tree,dfs,binary-tree,lca
complexity:
- time = O(n)
- space = O(n)
notes: find LCA for deepest leaves in a single DFS traversal by just finding the
node with equal depths between its two children.
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
  pair<int, TreeNode *> dfs(TreeNode *n) {
    if (!n)
      return {0, nullptr};
    auto [ld, lr] = dfs(n->left);
    auto [rd, rr] = dfs(n->right);
    if (ld > rd)
      return {ld + 1, lr};
    if (rd > ld)
      return {rd + 1, rr};
    return {ld + 1, n};
  }

public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) { return dfs(root).second; }
};
