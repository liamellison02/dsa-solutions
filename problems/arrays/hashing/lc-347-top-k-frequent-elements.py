"""
platform: lc
id: 347
name: top-k-frequent-elements
pattern: arrays/hashing
tags: hashmap,bucket-sort
complexity:
- time = O(n)
- space = O(n)
notes: bucket sort approach
"""
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        countMap = {}
        freq = [[] for i in range(len(nums) + 1)]

        for n in nums:
            countMap[n] = countMap.get(n, 0) + 1
        for n, c in countMap.items():
            freq[c].append(n)

        res = []
        for i in range(len(freq)-1, 0, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
