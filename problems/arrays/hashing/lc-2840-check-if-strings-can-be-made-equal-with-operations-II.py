"""
platform: lc
id: 2840
name: check if strings can be made equal with operations II
pattern: arrays/hashing
tags: hashmap,frequency,string
complexity:
- time = O(n)
- space = O(n)
notes:
just check if odd idx and even idx freq match btwn s1 & s2.
"""

from collections import Counter


class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        return Counter(s1[::2]) == Counter(s2[::2]) and Counter(s1[1::2]) == Counter(
            s2[1::2]
        )
