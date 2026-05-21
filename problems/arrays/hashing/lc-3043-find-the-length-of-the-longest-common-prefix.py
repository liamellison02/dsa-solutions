"""
platform: lc
id: 3043
name: find the length of the longest common prefix
pattern: arrays/hashing
tags: set,hashset,hashing,prefix,string
complexity:
m = len(arr1)
n = len(arr2)
N = m + n
max N = 100,000
L = max arr1[i], arr2[i] = 100,000,000 = 10^8
- time = O(N * L)
- space = O(N * L)

notes:
prefix set solution
0) set smaller arr as anchor
1) build prefix set from all nums in anchor arr
2) for each num in non-anchor, check for prefixes in prefix set w/ early return

"""

from typing import List


class Solution:
    def longestCommonPrefix(self, A: List[int], B: List[int]) -> int:
        if len(B) < len(A):
            A, B = B, A

        prefixes = set()
        for n in A:
            while n:
                prefixes.add(n)
                n //= 10

        res, nmin = 0, 1
        for n in B:
            if n < nmin:
                continue

            length = len(str(n))
            while length > res:
                if n in prefixes:
                    res = length
                    nmin = 10**res
                    break
                n //= 10
                length -= 1

        return res
