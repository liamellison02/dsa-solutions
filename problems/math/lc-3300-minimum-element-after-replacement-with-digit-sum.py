"""
platform: lc
id: 3300
name: minimum element after replacement with digit sum
pattern: math
tags: math,digit-sum,string
complexity:
n = len(nums), d = max digits in any element
- time = O(n*d)
- space = O(d) = O(1)
notes:
bruh j do it
"""

from typing import List


class Solution:
    def minElement(self, nums: List[int]) -> int:
        return min(sum(map(int, str(n))) for n in nums)
