"""
platform: lc
id: 33
name: search in rotated sorted array
pattern: binary_search/on_array
tags: binary-search,sorting,sorted,arrays
complexity:
- time = O(logn)
- space = O(1)
notes:
canonical modified binary search problem
need to separate each search step into two cases:
a) arr[l] <= arr[mid]
b) arr[l] > arr[mid]

from there, it's just modified binary search
"""

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] == target:
                return m

            if nums[l] <= nums[m]:
                if target < nums[l] or target > nums[m]:
                    l = m + 1
                else:
                    r = m - 1

            else:
                if nums[m] > target or target > nums[r]:
                    r = m - 1
                else:
                    l = m + 1

        return -1
