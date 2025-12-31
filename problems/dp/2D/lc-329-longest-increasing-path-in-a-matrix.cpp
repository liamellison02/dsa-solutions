/*
platform: lc
id: 329
name: longest increasing path in a matrix
pattern: dp/2D
tags: dp,graph,DAG,kahns,BFS,DFS,grid,matrix,topological,optimization
complexity:
- time = O(m*n)
- space = O(m*n)
notes: build indegree based on increasing edges, bfs by levels (like topo
layers)
*/

#include <algorithm>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
using VPI = vector<PI>;
using VTI = vector<TI>;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    VVI ind(m, VI(n, 0));
    static int dirs[5] = {1, 0, -1, 0, 1};

    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        int v = matrix[i][j];
        for (int d{}; d < 4; ++d) {
          int ni = i + dirs[d], nj = j + dirs[d + 1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            continue;
          if (matrix[ni][nj] > v)
            ++ind[ni][nj];
        }
      }
    }

    queue<pair<int, int>> q;
    for (int i{}; i < m; ++i)
      for (int j{}; j < n; ++j)
        if (ind[i][j] == 0)
          q.emplace(i, j);

    int res = 0;
    while (!q.empty()) {
      int sz = q.size();
      ++res;
      while (sz--) {
        auto [i, j] = q.front();
        q.pop();
        int v = matrix[i][j];

        for (int d{}; d < 4; ++d) {
          int ni = i + dirs[d], nj = j + dirs[d + 1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            continue;
          if (matrix[ni][nj] > v)
            if (--ind[ni][nj] == 0)
              q.emplace(ni, nj);
        }
      }
    }

    return res;
  }
};
