/*
platform: lc
id: 1260
name: shift 2d grid
difficulty: easy
url: https://leetcode.com/problems/shift-2d-grid/
pattern: arrays/simulation
tags: matrix,grid,simulation,math
complexity:
- time = O(m*n)
- space = O(m*n)
notes:
treat grid as 1d row-major
shift each cell by k

flatten col: nj = j + k
row: ni = (i + nj/n) % m, nj %= n
*/

#include <vector>

using namespace std;

#define rep(i, n) for (int i{0}; i < (n); ++i)

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    k %= (m*n);
    if (k==0) return grid;

    vvi res(m, vi(n));

    rep(i, m) {
      rep(j, n) {
        int ni = i;
        int nj = j + k;

        ni = (ni + nj / n) % m;
        nj = nj % n;

        res[ni][nj] = grid[i][j];
      }
    }

    return res;
  }
};
