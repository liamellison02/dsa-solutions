"""
platform: lc
id: 242
name: valid-anagram
difficulty: easy
url: https://leetcode.com/problems/valid-anagram/
pattern: arrays/hashing
tags: hashmap,frequency-count
complexity:
- time = O(n)
- space = O(1) for fixed alphabet size
notes: increment char counts for s, decrement for t; if any count goes negative or total != 0, not an anagram
"""
import string

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hm = dict.fromkeys(string.ascii_lowercase, 0)
        total = 0

        for c in s:
            hm[c]+=1
            total+=1
        for i in t:
            if hm[i] > 0:
                hm[i]-=1
                total-=1
            else:
                return False

        return True if total == 0 else False
