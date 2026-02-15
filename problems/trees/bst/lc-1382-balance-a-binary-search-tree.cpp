/*
platform: lc
id: 1382
name: balance a binary search tree
difficulty: medium
url: https://leetcode.com/problems/balance-a-binary-search-tree/
pattern: trees/bst
tags: tree,bst,sorting,inorder-traversal,stack
complexity:
- time = O(n)
- space = O(n)
notes:
build a sorted list of the input nodes using IOT.
using the sorted list, rebuild recursively using divide and conquer.
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using Vll = vector<ll>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVll = vector<Vll>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;

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
  vector<TreeNode *> srtd;

public:
  TreeNode *rebuild(int l, int r) {
    if (l > r)
      return nullptr;

    int mid = l + (r - l) / 2;

    TreeNode *node = srtd[mid];
    node->left = rebuild(l, mid - 1);
    node->right = rebuild(mid + 1, r);

    return node;
  }

  TreeNode *balanceBST(TreeNode *root) {
    srtd.clear();
    stack<TreeNode *> stk;

    auto curr = root;

    while (curr || !stk.empty()) {
      while (curr) {
        stk.push(curr);
        curr = curr->left;
      }

      curr = stk.top();
      stk.pop();
      srtd.push_back(curr);
      curr = curr->right;
    }

    return rebuild(0, srtd.size() - 1);
  }
};
