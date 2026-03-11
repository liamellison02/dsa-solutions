"""
platform: lc
id: 560
name: subarray sum equals k
pattern: arrays/prefix_sum
tags: hashmap,hashtable,complement,frequency,enumeration,prefix-sum
complexity:
- time = O(n)
- space = O(n)
notes:

key insight:
let 0 <= i <= j <= nums.length
sum(nums[:j]) - sum(nums[:i]) = sum(nums[i:j])

given this, if we want to find where sum(nums[i:j]) = k,
we can populate the prefix sum frequencies into hashtable,
and for each prefix sum, sum(nums[:i]):
- if there exists prior prefix sums equal to (sum(nums[:i]) - k)
   - increment our res by count(sum[nums[:i]) - k) from freq hashtable

"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res, curr, sums = 0, 0, {0: 1}
        for n in nums:
            curr += n
            if curr - k in sums:
                res += sums[curr - k]
            sums[curr] = sums.get(curr, 0) + 1
        return res
