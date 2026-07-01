"""
platform: lc
id: 2812
name: find the safest path in a grid
difficulty: medium
url: https://leetcode.com/problems/find-the-safest-path-in-a-grid/
pattern: graphs/shortest_path
tags: bfs,dijkstras,shortest-path,grid,priority-queue
complexity:
n = grid side length
- time = O(E * logE) = O(n^2 * logn)
- space = O(V) = O(n*n)
notes:
1. convert grid to manhattan dists from nearest thief
    (multi-source bfs from each i,j containing a thief)
2. dijkstras
    runs on the converted grid

"""

from typing import List
from collections import deque
from heapq import heappop_max, heappush_max


class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        """
        1. convert grid to manhattan dists from nearest thief
            (multi-source bfs from each i,j containing a thief)
        2. dijkstras
            runs on the converted grid
        """
        n = len(grid)
        if n == 1:
            return 0

        INF = float("inf")
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        def notOOB(a, b, n):
            return 0 <= a < n and 0 <= b < n

        dlta = [[INF] * n for _ in range(n)]

        bfs = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    bfs.append((i, j, 0))

        while bfs:
            i, j, d = bfs.popleft()
            if dlta[i][j] != INF:
                continue

            dlta[i][j] = d
            for dx, dy in dirs:
                nx, ny = i + dx, j + dy
                if notOOB(nx, ny, n) and dlta[nx][ny] == INF:
                    bfs.append((nx, ny, d + 1))

        prune = [[False] * n for _ in range(n)]
        maxh = []  # currmin, i, j
        heappush_max(maxh, (dlta[0][0], 0, 0))

        while maxh:
            curr, i, j = heappop_max(maxh)
            if i == n - 1 and j == n - 1:
                return curr

            if prune[i][j]:
                continue

            prune[i][j] = True

            for dx, dy in dirs:
                nx, ny = i + dx, j + dy
                if notOOB(nx, ny, n) and not prune[nx][ny]:
                    heappush_max(maxh, (min(curr, dlta[nx][ny]), nx, ny))

        return 0
