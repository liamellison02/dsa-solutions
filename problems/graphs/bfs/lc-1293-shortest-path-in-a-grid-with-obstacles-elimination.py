"""
platform: lc
id: 1293
name: shortest path in a grid with obstacles elimination
difficulty: hard
url: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
pattern: graphs/bfs
tags: bfs,grid,shortest-path,matrix,state
complexity:
V = m*n*k, E = O(4*V)
- time = O(V + E) = O(m*n*k)
- space = O(V) = O(m*n*k)
notes:
bfs over (i,j,rem_elims)
remaining budget is part of the visited key
"""

from typing import List

from collections import deque


class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])

        if k >= m + n - 2:
            return m + n - 2

        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        q = deque([(0, 0, k, 0)])
        visited = set([(0, 0, k)])

        while q:
            i, j, r, s = q.popleft()
            if i == m - 1 and j == n - 1:
                return s

            for di, dj in dirs:
                ni, nj = i + di, j + dj
                if not (0 <= ni < m and 0 <= nj < n):
                    continue

                nr = r - grid[ni][nj]
                if nr < 0 or (ni, nj, nr) in visited:
                    continue

                visited.add((ni, nj, nr))
                q.append((ni, nj, nr, s + 1))

        return -1
