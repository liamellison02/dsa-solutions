"""
platform: lc
id: 5
name: longest-palindromic-substring
pattern: strings
tags: palindrome,brute-force
complexity:
- time = O(n^2)
- space = O(1)
notes:
"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 1:
            return s

        if s == s[::-1]:
            return s

        longest = ""
        curr = ""
        temp = ""
        for i in range(len(s)-1, -1, -1):
            curr = ""
            for j in range(len(s)):
                if i == j:
                    if len(curr) == 0:
                        curr = s[i]
                else:
                    temp = s[j:i+1]
                    if temp == temp[::-1]:
                        if len(temp) > len(curr):
                            curr = temp

            if len(curr) > len(longest):
                longest = curr

        return longest
