/*
platform: lc
id: 743
name: network delay time
difficulty: hard
url: https://leetcode.com/problems/network-delay-time/
pattern: graphs/shortest_path
tags: dijkstras,heap
complexity: O(ElogE) time, O(E) space : E = # of edges
notes: simple dijkstras problem, solution likely has room for
micro-optimizations
*/

#include <queue>
#include <vector>
using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;
using VPI = vector<PII>;
using VVPI = vector<VPI>;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    VVPI adj(n + 1);
    VI dist(n + 1, -1);

    for (VI &t : times)
      adj[t[0]].push_back({t[1], t[2]});

    priority_queue<PII, VPI, greater<PII>> minh;

    minh.push({0, k});
    while (!minh.empty()) {
      auto [d, v] = minh.top();
      minh.pop();

      if (dist[v] != -1)
        continue;

      dist[v] = d;

      for (auto &[n, w] : adj[v]) {
        if (dist[n] == -1)
          minh.push({d + w, n});
      }
    }

    int tf = 0;
    for (int i = 1; i <= n; ++i) {
      if (dist[i] == -1)
        return -1;
      tf = max(tf, dist[i]);
    }

    return tf;
  }
};
