"""
platform: lc
id: 16
name: 3sum closest
pattern: arrays/two_pointers
tags: two-pointers,array,sorting
complexity:
- time = O(n*n)
- space = O(1)
notes:
sort nums, gives directional information
then use two pointers
"""

from typing import *


class Solution:
    def threeSumClosest(self, nums: List[int], k: int) -> int:
        N = len(nums)
        res, best = 0, float("inf")
        nums.sort()

        for i in range(N - 2):
            l, r = i + 1, N - 1
            while l < r:
                curr = nums[i] + nums[l] + nums[r]
                if abs(curr - k) < best:
                    res = curr
                    best = abs(curr - k)
                if curr > k:
                    r -= 1
                elif curr < k:
                    l += 1
                else:
                    return k

        return res
