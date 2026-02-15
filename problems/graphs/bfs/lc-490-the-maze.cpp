/*
platform: lc
id: 490
name: the maze
difficulty: medium
url: https://leetcode.com/problems/the-maze/
pattern: graphs/bfs
tags: bfs,dfs,matrix,paths
complexity:
- time = O(m*n)
- space = O(m*n)
notes: simple bfs to find path existence, only mark stopping cells as visited
*/

#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VC = vector<char>;
using VI = vector<int>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVS = vector<VS>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start,
               vector<int> &destination) {
    int m = maze.size(), n = maze[0].size();
    vector<vector<char>> visit(m, vector<char>(n, 0));
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    visit[start[0]][start[1]] = 1;

    while (!q.empty()) {
      auto [row, col] = q.front();
      q.pop();

      if (row == destination[0] && col == destination[1])
        return true;

      for (auto &dir : dirs) {
        int r = row, c = col;

        while (r + dir[0] >= 0 && r + dir[0] < m && c + dir[1] >= 0 &&
               c + dir[1] < n && maze[r + dir[0]][c + dir[1]] == 0) {
          r += dir[0];
          c += dir[1];
        }

        if (!visit[r][c]) {
          visit[r][c] = 1;
          q.push({r, c});
        }
      }
    }

    return false;
  }
};
