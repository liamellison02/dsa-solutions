/*
platform: lc
id: 778
name: swim in rising water
pattern: graphs/shortest_path
tags: dijkstras,heap,matrix,grid
complexity:
n = grid.size()
- time = O(n^2 * logn)
- space = O(n^2)
notes: use modified dijkstra's to find path w/ minimum largest cell in path
*/

#include <functional>
#include <queue>
#include <vector>

using namespace std;

using TI = tuple<int, int, int>;

using VC = vector<char>;
using VVC = vector<VC>;

using VI = vector<int>;
using VVI = vector<VI>;

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();

    static const int dr[4] = {1, 0, -1, 0};
    static const int dc[4] = {0, 1, 0, -1};

    VVC visit(n, VC(n, 0));
    priority_queue<TI, vector<TI>, greater<TI>> minh;

    minh.push({grid[0][0], 0, 0});
    visit[0][0] = 1;

    while (!minh.empty()) {
      auto [t, r, c] = minh.top();
      minh.pop();

      if (r == n - 1 && c == n - 1)
        return t;

      for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
          continue;
        if (visit[nr][nc])
          continue;

        visit[nr][nc] = 1;
        minh.push({max(t, grid[nr][nc]), nr, nc});
      }
    }

    return n * n;
  }
};
