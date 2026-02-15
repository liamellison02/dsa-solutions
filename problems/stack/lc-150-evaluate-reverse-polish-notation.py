"""
platform: lc
id: 150
name: evaluate-reverse-polish-notation
difficulty: easy
url: https://leetcode.com/problems/evaluate-reverse-polish-notation/
pattern: stack
tags: stack,expression
complexity:
- time = O(n)
- space = O(n)
notes: push numbers onto stack; when an operator appears, pop two operands, apply the op, and push the result back. Note: for subtraction and division, the second popped value is the left operand
"""
from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operands = []

        for token in tokens:
            if token == '+':
                n = operands.pop()
                m = operands.pop()
                operands.append(n+m)
            elif token == '-':
                n = operands.pop()
                m = operands.pop()
                operands.append(m-n)
            elif token == '*':
                n = operands.pop()
                m = operands.pop()
                operands.append(n*m)
            elif token == '/':
                n = operands.pop()
                m = operands.pop()
                operands.append(int(m/n))
            else:
                operands.append(int(token))

        return operands.pop()
