/*
platform: lc
id: 286
name: walls and gates
difficulty: medium
url: https://leetcode.com/problems/walls-and-gates/
pattern: graphs/bfs
tags: bfs,matrix,array
complexity:
- time = O(m*n)
- space = O(m*n)
notes:
canonical bfs problem.
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

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

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
public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    int m = rooms.size(), n = rooms[0].size();
    queue<pair<int, int>> q;

    for (int i{}; i < m; ++i)
      for (int j{}; j < n; ++j)
        if (rooms[i][j] == 0)
          q.push({i, j});

    auto try_push = [&](int nr, int nc, int nd) {
      if (rooms[nr][nc] > nd) {
        rooms[nr][nc] = nd;
        q.push({nr, nc});
      }
    };

    while (!q.empty()) {
      auto [r, c] = q.front();
      int d = rooms[r][c];
      q.pop();

      if (r > 0)
        try_push(r - 1, c, d + 1);
      if (r + 1 < m)
        try_push(r + 1, c, d + 1);
      if (c > 0)
        try_push(r, c - 1, d + 1);
      if (c + 1 < n)
        try_push(r, c + 1, d + 1);
    }
  }
};
