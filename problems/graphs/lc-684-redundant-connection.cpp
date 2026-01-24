/*
platform: lc
id: 684
name: redundant-connection
pattern: graphs
tags: union-find,graph
complexity:
- time = O(n * alpha(n)) where alpha is inverse Ackermann
- space = O(n)
notes:
*/

#include <vector>

using namespace std;
using VI = vector<int>;

class Solution {
  bool unionOf(int x, int y, VI &rnk, VI &rt) {
    int A = find(x, rt);
    int B = find(y, rt);

    if (A == B)
      return false;

    if (rnk[A] > rnk[B])
      rt[B] = A;
    else if (rnk[B] > rnk[A])
      rt[A] = B;
    else {
      rt[B] = A;
      ++rnk[A];
    }
    return true;
  }

  int find(int a, VI &rt) {
    int r = rt[a];
    while (r != rt[r]) {
      rt[r] = rt[rt[r]];
      r = rt[r];
    }
    return r;
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    VI rank(n + 1, 0);
    VI root(n + 1, 0);
    for (int i{}; i < n; ++i)
      root[i] = i;
    for (auto &e : edges)
      if (!unionOf(e[0], e[1], rank, root))
        return e;
    return VI(2, 0);
  }
};
