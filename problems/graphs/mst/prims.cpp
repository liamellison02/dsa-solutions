#include <cstdint>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using namespace std;
using ll = long long;
using VI = vector<int>; // edges: {u, v, w}
using PII = pair<int, int>;
using VPI = vector<PII>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T> using uset = unordered_set<T>;

// returns total weight of the MST for an undirected graph (-1 if disconnected)
int prims(vector<VI> edges) {
  umap<int, VPI> adj;
  uset<int> nodes;

  for (VI &e : edges) {
    int u{e[0]}, v{e[1]}, w{e[2]};
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // undirected
    nodes.insert(u);
    nodes.insert(v);
  }

  if (nodes.empty())
    return 0;

  int start{*nodes.begin()};

  uset<int> MST;
  minpq<PII> heap; // (w, v)

  heap.push({0, start});

  ll total{0};

  while (!heap.empty()) {
    auto [w, u] = heap.top();
    heap.pop();

    if (MST.count(u))
      continue;

    MST.insert(u);
    total += w;

    for (auto &[v, wt] : adj[u])
      if (!MST.count(v))
        heap.push({wt, v});
  }

  return MST.size() == nodes.size() ? total : -1;
}
