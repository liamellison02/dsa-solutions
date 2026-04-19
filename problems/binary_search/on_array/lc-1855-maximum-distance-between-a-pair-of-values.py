"""
platform: lc
id: 1855
name: maximum distance between a pair of values
pattern: binary_search/on_array
tags: binary-search
complexity:
- time = O( min(m,n) * log(n) ) = O(min(m,n)logn)
- space = O(1)
notes:
reverse binary search on nums2 to find j for each i in nums1
"""

from typing import List


class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        res = 0

        for i in range(min(m, n)):
            j, l, r = i, i, n
            while l < r:
                m = (l + r) // 2
                if nums2[m] < nums1[i]:
                    r = m
                else:
                    j = m
                    l = m + 1

            if j - i > res:
                res = j - i

        return res
