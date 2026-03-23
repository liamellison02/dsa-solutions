"""
platform: lc
id: 63
name: unique paths II
pattern: dp/grid
tags: bottom-up,dp,grid,paths,enumeration
complexity:
- time = O(m * n)
- space = O(n)
notes:
unique paths but w/ constraints.
canonical bottom-up dp
"""

from typing import List


class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1
        for i in range(m):
            if i == 1:
                dp[0] = 0
            for j in range(1, n + 1):
                if grid[i][j - 1]:
                    dp[j] = 0
                else:
                    dp[j] += dp[j - 1]
        return dp[n]
