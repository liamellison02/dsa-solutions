"""
platform: lc
id: 566
name: reshape-the-matrix
difficulty: medium
url: https://leetcode.com/problems/reshape-the-matrix/
pattern: arrays/simulation
tags: matrix
complexity:
- time = O(m*n)
- space = O(1) excluding output
notes: flatten the matrix by iterating row-by-row and fill the new shape using a running column/row index; only valid if total element count matches r*c
"""
from typing import List

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        if (r == len(mat) and c == len(mat[0])) or r*c != len(mat)*len(mat[0]):
            return mat

        matrix = [[0 for i in range(c)] for j in range(r)]
        x, y = 0, 0

        for row in mat:
            for num in row:
                if not x < c:
                    y += 1
                    x = 0
                matrix[y][x] = num
                x += 1

        return matrix
