"""
platform: lc
id: 704
name: binary-search
pattern: binary_search
tags: binary-search
complexity:
- time = O(log n)
- space = O(1)
notes:
"""
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lb, rb, mid = 0, len(nums)-1, 0

        while lb <= rb:
            mid = (lb + rb) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                lb = mid + 1
            else:
                rb = mid - 1

        return -1
