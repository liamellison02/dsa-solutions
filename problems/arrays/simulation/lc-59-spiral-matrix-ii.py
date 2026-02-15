"""
platform: lc
id: 59
name: spiral-matrix-ii
difficulty: medium
url: https://leetcode.com/problems/spiral-matrix-ii/
pattern: arrays/simulation
tags: matrix,simulation
complexity:
- time = O(n^2)
- space = O(1) excluding output
notes: same boundary-shrinking approach as spiral matrix I but filling values 1..n^2 instead of reading them
"""
from typing import List

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0 for i in range(n)] for j in range(n)]
        lb, rb, ub, bb = 0, n, 0, n
        i = 1

        while lb < rb and ub < bb and i <= n*n:

            for j in range(lb, rb, 1):
                matrix[ub][j] = i
                i += 1
            ub += 1

            if not ub < bb:
                break

            j = ub
            while j < bb:
                matrix[j][rb-1] = i
                i += 1
                j += 1
            rb -= 1

            if not lb < rb:
                break

            for j in range(rb-1, lb-1, -1):
                matrix[bb-1][j] = i
                i += 1
            bb -= 1

            if not ub < bb:
                break

            j = bb-1
            while j >= ub:
                matrix[j][lb] = i
                i += 1
                j -= 1
            lb += 1

        return matrix
