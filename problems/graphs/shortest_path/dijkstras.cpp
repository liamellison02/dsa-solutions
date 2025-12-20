#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;

int dijkstras(vector<VI> edges, int src, int dest) {
  // returns shortest distance from src to dest, given the graph represented by
  // edges.

  unordered_map<int, vector<PII>> adj;
  unordered_map<int, int> shortest;

  for (VI &edge : edges) {
    int s = edge[0], d = edge[1], w = edge[2];
    adj[s].push_back({d, w});
  }

  priority_queue<PII> heap;
  heap.push({0, src});

  while (!heap.empty()) {
    auto [dist, vtx] = heap.top();
    heap.pop();

    if (shortest.count(vtx))
      continue;

    shortest[vtx] = dist;
    for (auto &[neighbor, weight] : adj[vtx]) {
      if (!shortest.count(neighbor))
        heap.push({weight + dist, neighbor});
    }
  }

  return shortest[dest];
}
