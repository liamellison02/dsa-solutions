"""
platform: lc
id: 1848
name: minimum distance to the target element
pattern: arrays/two_pointers
tags: arrays,two-pointers
complexity:
- time = O(n)
- space = O(1)
notes:
just find it bro
"""

from typing import List


class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        n = len(nums)

        if start >= n:
            init = n - 1
        elif start < 0:
            init = 0
        else:
            init = start

        l = r = init
        while l >= 0 or r < n:
            if l >= 0 and nums[l] == target:
                return abs(l - start)

            if r < n and nums[r] == target:
                return abs(r - start)

            r += 1
            l -= 1

        return -1
