"""
platform: lc
id: 128
name: longest consecutive sequence
pattern: arrays/hashing
tags: hashset,sequence,hashing
complexity:
- time = O(n)
- space = O(n)
notes:
just read the solution lol
"""

from typing import *


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        unique = set(nums)
        mx = 0
        for n in unique:
            if n - 1 in unique:
                continue

            cur = 1
            while n + 1 in unique:
                cur += 1
                n += 1
            if cur > mx:
                mx = cur

        return mx
