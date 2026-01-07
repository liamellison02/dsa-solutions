/*
platform: lc
id: 1339
name: maximum product of splitted binary tree
pattern: trees/dfs
tags: dfs,binary-tree,tree,postorder
complexity:
n = # of nodes, h = height of tree
- time = O(2 * n) = O(n)
- space = O(h)
notes: dfs to find total tree sum, then postorder dfs to find subtree sums
and max value of subtreeSum * (totalSum - subtreeSum) across the entire tree
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
  ll tot, mp;

  ll treesum(TreeNode *n) {
    return n ? n->val + treesum(n->left) + treesum(n->right) : 0;
  }

  ll dfs(TreeNode *n) {
    if (!n)
      return 0;
    ll s = n->val + dfs(n->left) + dfs(n->right);
    mp = max(mp, s * (tot - s));
    return s;
  }

public:
  int maxProduct(TreeNode *root) {
    tot = treesum(root);

    mp = 0;
    dfs(root);

    return mp % (ll)(1e9 + 7);
  }
};
