"""
platform: lc
id: 567
name: permutation-in-string
pattern: strings
tags: sliding-window,frequency-count
complexity:
- time = O(n)
- space = O(1) for fixed alphabet
notes:
"""

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1Chars = [0] * 26
        s2Chars = [0] * 26
        count = 0

        for i in range(len(s1)):
            s1Chars[ord(s1[i]) - ord('a')] += 1
            s2Chars[ord(s2[i]) - ord('a')] += 1

        for i in range(26):
            if s1Chars[i] == s2Chars[i]:
                count += 1

        if count == 26:
            return True

        for i in range(len(s1), len(s2)):
            l, r = ord(s2[i - len(s1)]) - ord('a'), ord(s2[i]) - ord('a')

            if s2Chars[l] == s1Chars[l]:
                count -= 1
            s2Chars[l] -= 1
            if s2Chars[l] == s1Chars[l]:
                count += 1

            if s2Chars[r] == s1Chars[r]:
                count -= 1
            s2Chars[r] += 1
            if s2Chars[r] == s1Chars[r]:
                count += 1

            if count == 26:
                return True

        return False
