#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

// sparse DSU — uses unordered_map, auto-initializes on first access
// use when node values are arbitrary ints or not known ahead of time
struct DSU {
  unordered_map<int, int> root, rank;

  int find(int x) {
    if (!root.count(x)) {
      root[x] = x;
      rank[x] = 0;
    }
    if (root[x] == x)
      return x;
    return root[x] = find(root[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (rank[a] < rank[b])
      swap(a, b);
    root[b] = a;
    if (rank[a] == rank[b])
      ++rank[a];
    return true;
  }

  bool same(int a, int b) { return find(a) == find(b); }
};

// dense DSU — uses vector, must call init(n) first
// use when nodes are 0..n-1 (graphs, grid problems, etc.)
struct DenseDSU {
  vector<int> root, rank;

  void init(int n) {
    root.resize(n);
    rank.assign(n, 0);
    for (int i = 0; i < n; ++i)
      root[i] = i;
  }

  int find(int x) {
    if (root[x] == x)
      return x;
    return root[x] = find(root[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (rank[a] < rank[b])
      swap(a, b);
    root[b] = a;
    if (rank[a] == rank[b])
      ++rank[a];
    return true;
  }

  bool same(int a, int b) { return find(a) == find(b); }

  int components() {
    int cnt = 0;
    for (int i = 0; i < (int)root.size(); ++i)
      if (find(i) == i)
        ++cnt;
    return cnt;
  }
};
