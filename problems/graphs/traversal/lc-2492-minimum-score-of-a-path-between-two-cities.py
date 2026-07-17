"""
platform: lc
id: 2492
name: minimum score of a path between two cities
difficulty: medium
url: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
pattern: graphs/traversal
tags: bfs,graph,connected-components
complexity:
- time = O(V + E)
- space = O(V + E)
notes:
path can revisit nodes + 1 and n are guaranteed connected
so answer is just min edge weight anywhere in 1's connected component

bfs the entire component tracking min edge seen
"""

from collections import defaultdict, deque
from typing import List


class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(dict)
        for a, b, d in roads:
            adj[a][b] = d
            adj[b][a] = d

        res = float("inf")
        visited = set()
        q = deque([1])
        visited.add(1)

        while q:
            u = q.popleft()
            for v, d in adj[u].items():
                res = min(res, d)
                if v not in visited:
                    visited.add(v)
                    q.append(v)

        return res
