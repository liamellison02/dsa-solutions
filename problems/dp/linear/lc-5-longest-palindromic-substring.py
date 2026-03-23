"""
platform: lc
id: 5
name: longest palindromic substring
pattern: dp/linear
tags: bottom-up,dp,string,palindrome,substring,two-pointers
complexity:
- time = O(n*n)
- space = O(1)
notes:
do i rly need to write anything here? (shoutout blackrock)
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        n, mx = len(s), 0
        ml, mr = -1, -1

        # evens
        for i in range(n - 1):
            l, r = i, i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > mx:
                    mx, ml, mr = r - l + 1, l, r
                l -= 1
                r += 1

        # odds
        for i in range(n):
            l, r = i, i
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > mx:
                    mx, ml, mr = r - l + 1, l, r
                l -= 1
                r += 1

        return s[ml: mr + 1]
