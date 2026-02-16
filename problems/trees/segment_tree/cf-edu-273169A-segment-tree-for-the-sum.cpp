/*
platform: cf-edu
id: 273169A
name: segment tree for the sum
url:
https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
course: 2
lesson: 4
pattern: trees/segment_tree
tags: segment-tree,range-query
complexity:
notes:
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
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

struct SegmentTree {
  int n;
  vec<ll> tree;

  SegmentTree(int size) : n(size), tree(4 * size) {}

  void build(const VI &arr, int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = arr[tl];
    } else {
      int m{(tl + tr) / 2};

      build(arr, 2 * v, tl, m);
      build(arr, 2 * v + 1, m + 1, tr);

      tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    return;
  }

  ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return tree[v];
    else {
      int m{(tl + tr) / 2};
      return query(2 * v, tl, m, l, min(r, m)) +
             query(2 * v + 1, m + 1, tr, max(l, m + 1), r);
    }
  }

  void set(int v, int tl, int tr, int idx, int val) {
    if (tl == tr) {
      tree[v] = val;
    } else {
      int m{(tl + tr) / 2};
      if (idx <= m)
        set(2 * v, tl, m, idx, val);
      else
        set(2 * v + 1, m + 1, tr, idx, val);
      tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vec<int> arr(n);
  rep(i, n) cin >> arr[i];

  SegmentTree tree(n);
  tree.build(arr, 1, 0, n - 1);

  while (m--) {
    int op, a, b;
    cin >> op >> a >> b;

    if (op == 1)
      tree.set(1, 0, n - 1, a, b);
    else
      cout << tree.query(1, 0, n - 1, a, b - 1) << '\n';
  }

  return 0;
}
