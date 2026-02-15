"""
platform: lc
id: 78
name: subsets
difficulty: easy
url: https://leetcode.com/problems/subsets/
pattern: backtracking
tags: backtracking,recursion,iterative
complexity:
- time = O(n * 2^n)
- space = O(n) for recursion stack
notes: iterative stack-based approach
"""
from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = []
        stack = [([], 0)]
        currSet, i = None, 0
        while stack:
            currSet, i = stack.pop()
            if i < len(nums):
                stack.append((currSet.copy(), i+1))
                currSet.append(nums[i])
                stack.append((currSet, i+1))
            else:
                subsets.append(currSet)

        return subsets
