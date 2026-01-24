"""
platform: lc
id: 20
name: valid-parentheses
pattern: stack
tags: stack,matching
complexity:
- time = O(n)
- space = O(n)
notes:
"""

class Solution:
    def isValid(self, s: str) -> bool:
        opens = [ '(', '{', '[' ]
        closes = [ ')', '}', ']' ]
        stack = []

        for v in s:
            if v in opens:
                stack.append(v)
            elif v in closes:
                if len(stack)==0:
                    return False
                if closes.index(v) == opens.index(stack[len(stack)-1]):
                    stack.pop()
                else:
                    return False
            else:
                return False

        return True if len(stack) == 0 else False
