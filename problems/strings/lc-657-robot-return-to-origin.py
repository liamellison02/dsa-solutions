"""
platform: lc
id: 657
name: robot return to origin
pattern: strings
tags: simulation,string,enumeration,count,frequency
complexity:
- time = O(n)
- space = O(1)
notes:
bruh.
"""

from collections import Counter


class Solution:
    def judgeCircle(self, moves: str) -> bool:
        cnt = Counter(moves)
        return cnt["R"] == cnt["L"] and cnt["U"] == cnt["D"]
