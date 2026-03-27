"""
platform: lc
id: 2946
name: matrix similarity after cyclic shifts
pattern: arrays/simulation
tags: simulation,matrix,grid
complexity:
- time = O(m * n)
- space = O(1)
notes:
just do it bruh.
"""

from typing import List


class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        if len(mat[0]) == k:
            return True

        for i, row in enumerate(mat):
            for j, val in enumerate(row):
                if val != mat[i][(j + k) % len(row)]:
                    return False

        return True
