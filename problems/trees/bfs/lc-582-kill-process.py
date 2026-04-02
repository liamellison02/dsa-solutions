"""
platform: lc
id: 582
name: kill process
pattern: trees/bfs
tags: bfs,tree,dfs,hashmap,hash-table,queue
complexity:
- time = O(n)
- space = O(n)
notes:
just do bfs or dfs lol
"""

from typing import List
from collections import defaultdict


class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        nodes = defaultdict(list)
        for child, parent in zip(pid, ppid):
            nodes[parent].append(child)

        bfs, i = [kill], 0
        while i < len(bfs):
            for child in nodes[bfs[i]]:
                bfs.append(child)
            i += 1

        return bfs
