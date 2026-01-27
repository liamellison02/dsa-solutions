/*
platform: lc
id: 3650
name: minimum cost path with edge reversal
pattern: graphs/shortest_path
tags: dijkstras,shortest_path,graphs,priority-queue,minheap,heap
complexity:
- time = O(n + mlogm)
- space = O(n+m)
notes:
dijkstras lol
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
  int minCost(int n, vector<vector<int>> &edges) {
    VVPI adj(n);

    for (auto &e : edges) {
      int u{e[0]}, v{e[1]}, w{e[2]};
      adj[u].push_back({v, w});
      adj[v].push_back({u, 2 * w});
    }

    Vll dist(n, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (u == n - 1)
        return d;
      if (d > dist[u])
        continue;

      for (auto &[v, w] : adj[u]) {
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.push({dist[v], v});
        }
      }
    }

    return -1;
  }
};
