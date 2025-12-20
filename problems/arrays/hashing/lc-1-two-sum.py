"""
platform: lc
id: 1
name: two sum
pattern: arrays/hashing
tags: hashmap,complement
complexity: O(n) time, O(n) space
notes:
"""

class Solution:
    def twoSum(self, nums, target):
        hashMap = {}
        index = 0
        diff = 0

        for item in nums:
            diff = target - item
            if diff in hashMap:
                return [hashMap[diff], index]
            hashMap[item] = index
            index += 1

