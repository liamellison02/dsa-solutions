"""
platform: lc
id: 1752
name: check if array is sorted and rotated
pattern: arrays/sorting
tags: array,counting,circular-array
complexity:
- time = O(n)
- space = O(1)
notes:
first check how many inversions/rotations
then need to check for nums[0] >= nums[-1] at the end
"""

from typing import List


class Solution:
    def check(self, nums: List[int]) -> bool:
        rot = 1
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                rot -= 1
                if rot < 0:
                    return False
        if nums[0] < nums[-1]:
            rot -= 1
        return True if rot >= 0 else False
