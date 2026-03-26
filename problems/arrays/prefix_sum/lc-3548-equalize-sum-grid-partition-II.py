"""
platform: lc
id: 3548
name: equalize sum grid partition II
pattern: arrays/prefix_sum
tags: prefix-sum,grid,matrix,array,suffix,enumeration
complexity:
- time = O()
- space = O()
notes:
"""

from collections import defaultdict
from typing import List


"""


turn each row, col into a set
perform v1 problem solution but at each check:
- lookup in hashmap for existence of complement


what cases does erasing a cell result in disconnectivity?
if count(rows/cols in split) == 1 && cell is not at the end of row/col


algo:
0) build hashmap of (cell_value -> list of indices)
1) check for vertical cuts:
    a) build suffix sums from last col -> first col
    b) set curr = curr running prefix sum for column i
    c) check delta btwn:
        - prefix sum for i (curr)
        - suffix sum for i
    d) if delta != 0:
        - check for existence + location for delta
        - if delta exists in grid && no disconnectivity:
            - return True

2) check for horizontal cuts (same as step 1)

3) return False


"""


class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        lookup = defaultdict(list)
        for i in range(m):
            for j in range(n):
                lookup[grid[i][j]].append((i, j))

        cols = [0 for _ in range(n)]
        for j in range(n - 2, -1, -1):
            cols[j] = sum(grid[i][j + 1] for i in range(m)) + cols[j + 1]

        rows = [0 for _ in range(m)]
        for i in range(m - 2, -1, -1):
            rows[i] = sum(grid[i + 1][j] for j in range(n)) + rows[i + 1]

        curr = sum(grid[i][0] for i in range(m))
        for j in range(n - 1):
            suffix = cols[j]
            if curr == suffix:
                return True

            diff = abs(suffix - curr)
            if curr > suffix:
                for r, c in lookup[diff]:
                    if c <= j and (m == 1 or (m > 1 and not (m > 2 and r == 1))):
                        return True
            else:
                for r, c in lookup[diff]:
                    if c > j and (m == 1 or (m > 1 and not (m > 2 and r == 1))):
                        return True

            curr += cols[j] - cols[j + 1]

        curr = sum(grid[0][j] for j in range(n))
        for i in range(m - 1):
            suffix = rows[i]
            if curr == suffix:
                return True

            diff = abs(rows[i] - curr)
            if curr > suffix:
                for r, c in lookup[diff]:
                    if r <= i and (n == 1 or (n > 1 and not (n > 2 and c == 1))):
                        return True
            else:
                for r, c in lookup[diff]:
                    if r > i and (n == 1 or (n > 1 and not (n > 2 and c == 1))):
                        return True

            curr += rows[i] - rows[i + 1]

        return False
