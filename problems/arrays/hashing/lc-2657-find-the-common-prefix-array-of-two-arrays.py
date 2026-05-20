"""
platform: lc
id: 2657
name: find the common prefix array of two arrays
pattern: arrays/hashing
tags: hashmap,hashtable,hashing,bitmask,arrays,frequency
complexity:
- time = O(n)
- space = O(n)
notes:
could be O(1) w/ bitmask since n < 50
just think abt it lol
"""

from typing import List


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        a, b = set(), set()
        res = [0 for _ in range(len(A))]

        for i in range(len(A)):
            res[i] = res[i - 1]

            if A[i] == B[i]:
                res[i] += 1
            else:
                if A[i] in b:
                    res[i] += 1
                if B[i] in a:
                    res[i] += 1

            a.add(A[i])
            b.add(B[i])

        return res
