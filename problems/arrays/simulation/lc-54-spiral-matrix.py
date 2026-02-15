"""
platform: lc
id: 54
name: spiral-matrix
difficulty: medium
url: https://leetcode.com/problems/spiral-matrix/
pattern: arrays/simulation
tags: matrix,simulation
complexity:
- time = O(m*n)
- space = O(1) excluding output
notes: maintain four shrinking boundaries (left, right, top, bottom); traverse each edge then shrink that boundary inward, breaking if bounds cross
"""
from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        lb, rb, tb, bb = 0, len(matrix[0]), 0, len(matrix)
        output = []

        while lb < rb or tb < bb:

            # Traverse top row, left to right
            if lb < rb:
                for num in matrix[tb][lb:rb]:
                    output.append(num)
            else:
                break
            tb += 1

            # Traverse far right column, top to bottom
            if tb < bb:
                i = tb
                while i < bb:
                    output.append(matrix[i][rb-1])
                    i += 1
            else:
                break
            rb -= 1

            # Traverse bottom row, right to left
            if lb < rb:
                for i in range(rb-1, lb-1, -1):
                    output.append(matrix[bb-1][i])
            else:
                break
            bb -= 1

            # Traverse far left column, bottom to top
            if tb < bb:
                i = bb - 1
                while i >= tb:
                    output.append(matrix[i][lb])
                    i -= 1
            else:
                break
            lb += 1

        return output
