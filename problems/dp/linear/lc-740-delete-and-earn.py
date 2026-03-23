"""
platform: lc
id: 740
name: delete and earn
pattern: dp/linear
tags: bottom-up,dp,linear,array,sorting,frequency,counting
complexity:
k = max value in nums
- time = O(n + k)
- space = O(n + k)
notes:
bottom-up approach
just iterate up the range of values, taking either:
- the prev value's best
- the prev prev value's best + curr val pts

"""

from typing import List
from collections import defaultdict


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        best = defaultdict(int)
        mx = 0
        for num in nums:
            best[num] += num
            mx = max(mx, num)

        a, b = 0, best[1]
        for n in range(2, mx + 1):
            a, b = b, max(b, a + best[n])

        return b
