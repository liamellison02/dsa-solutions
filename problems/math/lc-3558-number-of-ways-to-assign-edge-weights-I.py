"""
platform: lc
id: 3558
name: number of ways to assign edge weights I
pattern: math
tags: combinatorics,tree,bfs,parity
complexity:
n = number of nodes, d = edges on the longest root->leaf path
- time = O(n)
- space = O(n)
notes:
weight is 1 (odd) or 2 (even), so a path's parity = how many weight-1 edges it took
answer only cares about d = longest path; over its d edges half of the 2^d assignments are even -> 2^(d-1)
bfs from the root just to measure d (max depth in edges); pow does the modular exponentiation w/ 1e9+7
"""

from collections import defaultdict, deque
from typing import *


class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        tree = defaultdict(list)
        for u, v in edges:
            tree[min(u, v)].append(max(u, v))

        d = 0
        bfs = deque()
        bfs.append((tree[1], 0))

        while bfs:
            curr, lvl = bfs.popleft()
            if lvl > d:
                d = lvl
            for c in curr:
                bfs.append((tree[c], lvl + 1))

        return pow(2, d - 1, 10**9 + 7)
