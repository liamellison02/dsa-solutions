"""
platform: lc
id: 2540
name: minimum common value
pattern: arrays/two_pointers
tags: two-pointers,arrays,frequency
complexity:
- time = O(n + m)
- space = O(1)
notes:
walk up each arr until you find the min common value... duh
"""

from typing import List


class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        p1, p2 = 0, 0

        while p1 < m and p2 < n:
            if nums1[p1] < nums2[p2]:
                p1 += 1
            elif nums2[p2] < nums1[p1]:
                p2 += 1
            else:
                return nums1[p1]

        return -1
