"""
platform: lc
id: 3418
name: maximum amount of money robot can earn
pattern: dp/grid
tags: dp,grid,simulation,max-path,path
complexity:
- time = O(m * n)
- space = O(n)
notes:
basically just unique paths II w/ 3 possible neutralize ability states
at each step (0 used, 1 used, both used)
"""

from typing import List


class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        dp = [[float("-inf")] * 3 for _ in range(n + 1)]
        dp[0] = [0, float("-inf"), float("-inf")]

        for row in range(m):
            if row > 0:
                dp[0] = [float("-inf"), float("-inf"), float("-inf")]

            for i in range(1, n + 1):
                top, left = dp[i][:], dp[i - 1]
                val = coins[row][i - 1]

                if val >= 0:
                    dp[i][0] = max(left[0], top[0]) + val
                    dp[i][1] = max(left[1], top[1]) + val
                    dp[i][2] = max(left[2], top[2]) + val

                else:
                    dp[i][2] = max(max(left[2], top[2]) +
                                   val, max(left[1], top[1]))
                    dp[i][1] = max(max(left[1], top[1]) +
                                   val, max(left[0], top[0]))
                    dp[i][0] = max(left[0], top[0]) + val

        return max(dp[n])
