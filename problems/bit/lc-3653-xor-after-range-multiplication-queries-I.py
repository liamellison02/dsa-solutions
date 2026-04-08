"""
platform: lc
id: 3653
name: xor after range multiplication queries I
pattern: bit
tags: simulation,bitwise,bit-operations,xor
complexity:
n = len(nums)
m = len(queries) * avg((q[1]-q[0]) / q[2])
- time = O(m * n)
- space = O(1)
notes:
"""

from typing import List

MOD = 10**9 + 7


class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for l, r, k, v in queries:
            for i in range(l, r + 1, k):
                nums[i] = (nums[i] * v) % MOD

        res = 0
        for num in nums:
            res ^= num

        return res
