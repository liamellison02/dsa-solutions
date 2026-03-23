"""
platform: lc
id: 62
name: unique paths
pattern: dp/grid
tags: bottom-up,dp,grid,paths,enumeration
complexity:
- time = O(m * n)
- space = O(n)
notes:
canonical path finding in matrix problem.

could also swap n for min(m, n) for space optimization
or even compute the binomial coefficients
"""


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1
        for i in range(m):
            if i > 0:
                dp[0] = 0
            for j in range(1, n + 1):
                dp[j] = dp[j - 1] + dp[j]
        return dp[n]
