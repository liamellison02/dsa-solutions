/*
platform: lc
id: 787
name: cheapest flights within k stops
pattern: graphs/shortest_path
tags: dijkstras,heap,constraints
complexity:
V=n, E=flights.size()
- time = O(E*(k+1)*log(E*(k+1))
- space = O((k+1)*E + V*k)
notes: dijkstras with constraints
*/

#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using TI = tuple<int, int, int>;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> adj(n);

    for (auto &f : flights)
      adj[f[0]].push_back({f[1], f[2]});

    const int INF = numeric_limits<int>::max();
    vector<vector<int>> min_cost(n, vector<int>(k + 2, INF));

    priority_queue<TI, vector<TI>, greater<TI>> heap;

    heap.push({0, src, 0});
    min_cost[src][0] = 0;

    while (!heap.empty()) {
      auto [cost, u, s] = heap.top();
      heap.pop();

      if (cost != min_cost[u][s])
        continue;
      if (u == dst)
        return cost;
      if (s == k + 1)
        continue;

      for (auto &[v, w] : adj[u]) {
        int nc = cost + w;
        if (nc < min_cost[v][s + 1]) {
          min_cost[v][s + 1] = nc;
          heap.push({nc, v, s + 1});
        }
      }
    }

    return -1;
  }
};
