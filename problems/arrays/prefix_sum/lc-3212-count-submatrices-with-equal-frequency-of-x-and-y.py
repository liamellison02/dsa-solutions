"""
platform: lc
id: 3212
name: count submatrices with equal frequency of x and y
pattern: arrays/prefix_sum
tags: prefix-sum,matrix,counting,array
complexity:
- time = O(m*n)
- space = O(n)
notes:
use prefix sum arrays (per col):
++res if sumX[col] == sumY[col] && sumX[col] > 0 && sumY[col] > 0
"""

from typing import List


class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        X, Y = [0] * n, [0] * n

        res = 0
        for i in range(m):
            xi, yi = 0, 0
            for j in range(n):
                if grid[i][j] == "X":
                    xi += 1
                if grid[i][j] == "Y":
                    yi += 1

                X[j] += xi
                Y[j] += yi

                if X[j] == Y[j] and X[j] > 0:
                    res += 1

        return res
