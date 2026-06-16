"""
platform: lc
id: 3612
name: process string with special operations I
difficulty: medium
url: https://leetcode.com/problems/process-string-with-special-operations-i/
pattern: strings
tags: simulation,string,bytearray
complexity:
m = final length of res
- time = O(m + n), reverses can push worst case to O(m * n)
- space = O(m)
notes:
just simulate the problem statement gang...
use bytearray for them fast, C-level ops
"""


class Solution:
    def processStr(self, s: str) -> str:
        # NOTE: SE = "self-explanatory" bc some stuff is... well... SE.

        res = bytearray()  # better than both list and str (1 byte/elem vs. 8-byte ptr + char obj per elem); also is a lot faster bc later operations w/ res all run at the C level

        for c in s:  # iterate through each char in s
            if c == "*":  # case '*': rm last char if exists
                if res:  # non-empty safety check
                    del res[
                        -1
                    ]  # rm last char in res; del[-1] is O(1) and also doesnt return the char

            elif c == "#":  # case '#': dupe res onto itself
                res *= 2  # in-place duplication of res w/o rebinding to a new copy

            elif c == "%":  # case '%': reverse res
                res.reverse()  # most-optimal built-in reversal (no copies + runs at the C level)

            else:  # default case: appends lowercase english letter
                res.append(
                    ord(c)
                )  # add lowercase english char to res via int of c's ascii code (input constraints mean it's fine to assume valid input here)

        return res.decode()  # returns bytes as str
