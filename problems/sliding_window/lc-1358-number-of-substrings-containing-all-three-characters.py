"""
platform: lc
id: 1358
name: number of substrings containing all three characters
difficulty: medium
url: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
pattern: sliding_window
tags: sliding-window,string,counting
complexity:
- time = O(n)
- space = O(1)
notes:
track last seen i of a,b,c
iterate through all possible end idxes (2..n)
for each right end i, valid starts are 0..min(last),
so add min(last)+1 to res
"""


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res, last = 0, [-1, -1, -1]

        for i in range(len(s)):
            if s[i] == "a":
                last[0] = i
            elif s[i] == "b":
                last[1] = i
            elif s[i] == "c":
                last[2] = i

            lb = min(last)

            res += lb + 1

        return res
