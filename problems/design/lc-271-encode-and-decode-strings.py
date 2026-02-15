"""
platform: lc
id: 271
name: encode-and-decode-strings
difficulty: medium
url: https://leetcode.com/problems/encode-and-decode-strings/
pattern: design
tags: string,encoding
complexity:
- time = O(n)
- space = O(n)
notes: length-prefix encoding
"""
from typing import List

class Codec:
    def encode(self, strs: List[str]) -> str:
        ret = ""
        for s in strs:
            ret += str(len(s)) + '#' + s
        return ret

    def decode(self, s: str) -> List[str]:
        temp = ""
        currDelim = 0
        i = 0
        retArr = []
        while i < len(s):
            if currDelim == 0:
                while s[i] != "#":
                    temp += s[i]
                    i += 1
                currDelim = int(temp)
                if currDelim == 0:
                    retArr.append("")
                temp = ""
                i += 1
            else:
                retArr.append(s[i:i+currDelim])
                i += currDelim
                currDelim = 0

        return retArr
