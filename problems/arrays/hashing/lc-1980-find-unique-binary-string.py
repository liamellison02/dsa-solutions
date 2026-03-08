"""
platform: lc
id: 1980
name: find unique binary string
pattern: arrays/hashing
tags: hashset,enumeration,hashing,binary-string,strings
complexity:
- time = O(n*n)
- space = O(n)
notes:
string to int conversion for each num = O(n * n) time

build hashset of all unique integers from each binary representation,
enumerate first value not in unique (in range of [0...len(unique)+1]

key insight is you're guaranteed to have an answer in range: [0...len(unique)+1]

"""

from typing import *


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ints = set()
        for num in nums:
            ints.add(int(num, 2))

        for n in range(len(nums) + 1):
            if n not in ints:
                res = bin(n)[2:]
                return "0" * (len(nums) - len(res)) + res  # ensures len(res)=n
        return ""
