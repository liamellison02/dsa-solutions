"""
platform: lc
id: 1871
name: jump game VII
pattern: dp/linear
tags: dp,1d-dp,bottom-up,sliding-window,string,prefix-sum
complexity:
- time = O(n)
- space = O(n)
notes:
bottom-up boolean dp; dp[i] = can we land on index i
dp[i] is true when s[i] == '0' and some reachable j sits in jump window [i-maxJump, i-minJump]
instead of rescanning that window each step,
keep a running count of reachable indices inside it:
- index i-minJump enters the window once i >= minJump
- index i-maxJump-1 leaves the window once i > maxJump
so reachable > 0 means at least one valid takeoff point -> O(1) transition
early exit if s[-1] == '1' since the target itself must be a '0'

"""


class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        if s[-1] == "1":
            return False

        n = len(s)
        dp = [False] * n
        dp[0] = True

        reachable = 0
        for i in range(1, n):
            if i >= minJump and dp[i - minJump]:
                reachable += 1
            if i > maxJump and dp[i - maxJump - 1]:
                reachable -= 1
            dp[i] = s[i] == "0" and reachable > 0

        return dp[-1]
