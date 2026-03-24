"""
platform: lc
id: 139
name: word break
pattern: dp/linear
tags: dp,bottom-up,string
complexity:
let:
m = len(wordDict),
n = len(s),
k = sum(len(word for word in wordDict) / m
  = avg(len(word for word in wordDict))
- time = O(m * n * k)
- space = O(n)
notes:
classic dp problem.
do bottom-up solution.
"""

from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False for _ in range(n)]
        for i in range(n):
            for w in wordDict:
                if i < len(w) - 1:
                    continue
                if (i == len(w) - 1 or dp[i - len(w)]) and s[
                    i - len(w) + 1: i + 1
                ] == w:
                    dp[i] = True
                    break
        return dp[-1]
