"""
platform: lc
id: 3130
name: find all possible stable binary arrays II
pattern: dp/state_machine
tags: dp,combinatorics,top-down,prefix-sum,optimization,sliding-window
complexity:
- time = O(zero * one) = O(m*n) ?
- space = O(zero * one) = O(m*n) ?
notes:

top-down DP
i=[0..zero]
j=[0..one]

optimization trick:
- when appending a 0/1 where i/j is already at/above the limit,
  add the amount of combinations from the previous step (i-1/j-1),
  but subtract the amount of combinations where you have the same
  amount of the other bit, but i/j - limit - 1 of 0/1.
  e.g. if limit = 3 and j = 4, and you want to place 5 zeros (i=5):
    - your binary arr could look something like:
        - 110100100 (valid)
        - 010100110 (valid)
        - 011110000 (invalid)
        - 111010000 (invalid)
        - 011110000 (invalid)
        - 101110000 (invalid)
        - 110110000 (invalid)
    - you cant have 5 zeros to end a valid arr where len=i+j=9,
      so you need to consider all of the cases where:
        - i_prev = i-limit-1
        - j = 4
        - final bit is the opposite bit (1 in this case)
    - this amount is equal to dp[i-limit-1][j][1]
      or all valid strings ending in 1 with 4 ones and 1 zero:
        - 01111
        - 10111
        - 11011
        - 11101

"""

MOD = 10**9 + 7


class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        dp = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]

        for i in range(zero + 1):
            for j in range(one + 1):
                for b in range(2):
                    if i == 0:
                        if b == 0 or j > limit:
                            dp[i][j][b] = 0
                        else:
                            dp[i][j][b] = 1
                    elif j == 0:
                        if b == 1 or i > limit:
                            dp[i][j][b] = 0
                        else:
                            dp[i][j][b] = 1
                    elif b == 0:
                        dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1]
                        if i > limit:
                            dp[i][j][0] -= dp[i - limit - 1][j][1]
                    else:
                        dp[i][j][1] = dp[i][j - 1][0] + dp[i][j - 1][1]
                        if j > limit:
                            dp[i][j][1] -= dp[i][j - limit - 1][0]
                    dp[i][j][b] %= MOD

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD
