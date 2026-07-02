"""
platform: lc
id: 3286
name: find a safe walk through a grid
difficulty: medium
url: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
pattern: graphs/shortest_path
tags: dijkstras,grid,heap,shortest-path,matrix
complexity:
V = m*n grid cells (vertices), E = O(4*V) grid edges
- time = O(E log V) = O(m*n log(m*n))
- space = O(V) = O(m*n)
notes:
dijkstra's maximizing remaining health
"""

from typing import List
from heapq import heappush_max, heappop_max


class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        start = health - grid[0][0]
        if start < 1:
            return False

        best = [[-1] * n for _ in range(m)]
        best[0][0] = start
        maxh = [(start, 0, 0)]  # (health, i, j)

        while maxh:
            curr, i, j = heappop_max(maxh)

            if curr < best[i][j] or curr < 1:
                continue

            if i == m - 1 and j == n - 1:
                return True

            for di, dj in dirs:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n:
                    nh = curr - grid[ni][nj]
                    if nh >= 1 and nh > best[ni][nj]:
                        best[ni][nj] = nh
                        heappush_max(maxh, (nh, ni, nj))

        return False
