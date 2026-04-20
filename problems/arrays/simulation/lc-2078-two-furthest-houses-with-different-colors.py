"""
platform: lc
id: 2078
name: two furthest houses with different colors
pattern: arrays/simulation
tags: simulation
complexity:
- time = O(n)
- space = O(1)
notes:
just do it lol
"""

from typing import List


class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        res = 1

        for i in range(n):
            if colors[i] != colors[0]:
                res = max(res, i)
            if colors[i] != colors[-1]:
                res = max(res, n - i - 1)

        return res
