"""
platform: lc
id: 3121
name: count the number of special characters II
pattern: arrays/hashing
tags: array,hashing,string,counting
complexity:
- time = O(n)
- space = O(1) for fixed alphabet size
notes:
pretty simple lol
just track last lower & first uppper of each char
return count of indices that match the condition
"""


class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        firstup, lastlow = [-1] * 26, [len(word)] * 26
        for i, c in enumerate(word):
            ch = ord(c)
            if ch >= 97:
                lastlow[ch - 97] = i
            elif firstup[ch - 65] == -1:
                firstup[ch - 65] = i
        return sum(1 for i in range(26) if firstup[i] > lastlow[i])
