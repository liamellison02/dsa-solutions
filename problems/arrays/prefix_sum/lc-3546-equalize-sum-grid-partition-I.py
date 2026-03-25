"""
platform: lc
id: 3546
name: equalize sum grid partition I
url: https://leetcode.com/problems/equalize-sum-grid-partition-i/
pattern: arrays/prefix_sum
tags: prefix-sum,grid,matrix,array,suffix,enumeration
complexity:
- time = O(m * n) for both approaches
- space = O(m + n) for suffix arrays, O(1) for total sum
notes:

vertical cut -> col-based prefix + suffix sums
horizontal cut -> row-based prefix + suffix sums

approach #1 (suffix/lookup array):
- precompute suffix sums for rows + cols
- iterate col-by-col and then row-by-row:
    - compute/track running prefix sum
    - compare with suffix sum for valid cut

approach #2 (total sum):
- precompute total sum of the grid
- iterate col-by-col and then row-by-row:
    - keep a running prefix sum (`curr`)
    - if `2 * curr == total` at any point, return true

grid:
[1, 7, 8]
[2, 3, 0]

cols:
[18, 8, 0]

curr = 3
j = 0

if curr = cols[j]:
    return true
else:
    curr += cols[j] - cols[j+1]
"""

from typing import List


class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])

        cols = [0 for _ in range(n)]
        for j in range(n - 2, -1, -1):
            cols[j] = sum(grid[i][j + 1] for i in range(m)) + cols[j + 1]

        curr = sum(grid[i][0] for i in range(m))
        for j in range(n - 1):
            if curr == cols[j]:
                return True
            curr += cols[j] - cols[j + 1]

        rows = [0 for _ in range(m)]
        for i in range(m - 2, -1, -1):
            rows[i] = sum(grid[i + 1][j] for j in range(n)) + rows[i + 1]

        curr = sum(grid[0][j] for j in range(n))
        for i in range(m - 1):
            if curr == rows[i]:
                return True
            curr += rows[i] - rows[i + 1]
        return False

    def canPartitionGridMicroOptimized(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        tot = 0
        for row in grid:
            for val in row:
                tot += val

        curr = 0
        for j in range(n - 1):
            col = 0
            for i in range(m):
                col += grid[i][j]
            curr += col
            if 2 * curr == tot:
                return True

        curr = 0
        for i in range(m - 1):
            row = 0
            for val in grid[i]:
                row += val
            curr += row
            if 2 * curr == tot:
                return True

        return False
