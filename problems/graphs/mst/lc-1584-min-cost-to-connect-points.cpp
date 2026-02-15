/*
platform: lc
id: 1584
name: min cost to connect points
difficulty: medium
url: https://leetcode.com/problems/min-cost-to-connect-points/
pattern: graphs/mst
tags: mst,prims
complexity:
- time: O(n^2 * logn)
- space: O(n)
notes: MST problem, use prim's algorithm find MST between points and sum all the
  min "costs" (dist/weight of each edge in MST)
*/

#include <vector>
using namespace std;
using VI = vector<int>;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();

    VI dist(n, numeric_limits<int>::max());
    VI mst(n, -1);

    int c{};
    dist[0] = 0;

    for (int i{}; i < n; ++i) {
      int md = -1;
      int v;

      for (int j{}; j < n; ++j) {
        if (mst[j] == -1 && (md == -1 || dist[j] < md)) {
          md = dist[j];
          v = j;
        }
      }

      c += md;
      VI mp = points[v];

      int x = mp[0], y = mp[1];
      mst[v] = md;
      for (int p{}; p < n; ++p) {
        int d = abs(x - points[p][0]) + abs(y - points[p][1]);
        if (d != 0)
          dist[p] = min(dist[p], d);
      }
    }

    return c;
  }
};
