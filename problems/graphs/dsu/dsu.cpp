#include <unordered_map>
using namespace std;

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

  bool unionJoin(int a, int b) {
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
