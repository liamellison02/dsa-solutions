"""
platform: lc
id: 5
name: longest-palindromic-substring
difficulty: medium
url: https://leetcode.com/problems/longest-palindromic-substring/
pattern: strings
tags: palindrome,brute-force
complexity:
- time = O(n^2)
- space = O(1)
notes: brute force checks all substrings using reverse comparison; can be optimized to O(n^2) with expand-around-center approach
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
