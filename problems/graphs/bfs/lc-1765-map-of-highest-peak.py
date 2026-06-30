"""
platform: lc
id: 1765
name: map of highest peak
difficulty: medium
url: https://leetcode.com/problems/map-of-highest-peak/
pattern: graphs/bfs
tags: bfs,grid,matrix
complexity:
- time = O(m*n)
- space = O(m*n)
notes:
multi-source bfs from all water cells at once
seed every water cell at height 0, expand lvl by lvl
lvl at first cell visit = cell height (shortest dist from water)
"""

from collections import deque
from typing import List


class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        res = [[-1 for _ in range(n)] for _ in range(m)]

        q = deque()
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        for r in range(m):
            for c in range(n):
                if isWater[r][c] == 1:
                    q.append((r, c))
                    res[r][c] = 0

        lvl = 0
        while q:
            sz = len(q)

            for _ in range(sz):
                r, c = q.popleft()
                for d in dirs:
                    nr, nc = r + d[0], c + d[1]
                    if 0 <= nr < m and 0 <= nc < n and res[nr][nc] == -1:
                        res[nr][nc] = lvl + 1
                        q.append((nr, nc))

            lvl += 1

        return res
