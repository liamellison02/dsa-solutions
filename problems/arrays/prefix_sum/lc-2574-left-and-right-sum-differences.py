"""
platform: lc
id: 2574
name: left and right sum differences
pattern: arrays/prefix_sum
tags: prefix-sum,array,math
complexity:
- time = O(n)
- space = O(1)
notes:

pre[i] + suf[i] + nums[i] = total_sum

suf[i] = tot - pre[i] - nums[i]

pre[i] - suf[i] = pre[i] - tot + pre[i] + nums[i]

|pre[i] - suf[i]| = |2*pre[i] - tot + nums[i]|

answer[i] = |pre[i] - suf[i]|

"""

from itertools import accumulate
from typing import List


class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        """
        pre[i] + suf[i] + nums[i] = total_sum

        suf[i] = tot - pre[i] - nums[i]

        pre[i] - suf[i] = pre[i] - tot + pre[i] + nums[i]

        |pre[i] - suf[i]| = |2*pre[i] - tot + nums[i]|

        answer[i] = |pre[i] - suf[i]|
        """

        tot = sum(nums)
        return [
            abs(2 * pre - tot + n) for pre, n in zip(accumulate(nums, initial=0), nums)
        ]
