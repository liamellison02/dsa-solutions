"""
platform: lc
id: 3
name: longest-substring-without-repeating
pattern: strings
tags: sliding-window,hashset
complexity:
- time = O(n)
- space = O(min(n, alphabet size))
notes:
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        unique, longest, lb = set(), 0, 0

        for rb in range(len(s)):
            while s[rb] in unique:
                unique.remove(s[lb])
                lb += 1
            unique.add(s[rb])
            longest = max(longest, rb-lb+1)

        return longest
