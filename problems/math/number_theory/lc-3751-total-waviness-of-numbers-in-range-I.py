"""
platform: lc
id: 3751
name: total waviness of numbers in range I
pattern: math/number_theory
tags: enumeration,counting,digits,math,number-theory,bruteforce
complexity:
k = num2 - num1 + 1, d = digits in num2 (~log10)
- time = O(k*d)
- space = O(d) = O(1)
notes:
approach 1:
just simulate it through bruteforce, skip nums less than 100.

optimized:
range is bounded (<=1e5) so precompute waviness once per num into a
prefix sum, then any query is p[num2] - p[num1-1] in O(1).
use caching for optimized lookup table.
"""


class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        res = 0
        for num in range(num1, num2 + 1):
            n = [int(d) for d in str(num)]
            if len(n) < 3:
                continue

            cnt = 0
            for i in range(1, len(n) - 1):
                if n[i - 1] < n[i] and n[i + 1] < n[i]:
                    cnt += 1
                elif n[i - 1] > n[i] and n[i + 1] > n[i]:
                    cnt += 1
            res += cnt

        return res


class OptimizedSolution:
    _prefix = None

    @classmethod
    def _build(cls):
        N = 100_001
        prefix = [0] * N
        for x in range(100, N):
            s = str(x)
            w = 0
            for i in range(1, len(s) - 1):
                d = s[i]
                if s[i - 1] < d > s[i + 1] or s[i - 1] > d < s[i + 1]:
                    w += 1
            prefix[x] = prefix[x - 1] + w
        for x in range(1, 100):
            prefix[x] = prefix[x - 1]
        cls._prefix = prefix

    def totalWaviness(self, num1: int, num2: int) -> int:
        if Solution._prefix is None:
            Solution._build()
        p = Solution._prefix
        return p[num2] - p[num1 - 1]
