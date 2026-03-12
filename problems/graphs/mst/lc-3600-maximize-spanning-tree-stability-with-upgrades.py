"""
platform: lc
id: 3600
name: maximize spanning tree stability with upgrades
pattern: graphs/mst
tags: mst,dsu,union-find,graph,optimization,greedy,sorting,stack
complexity:
- time = O(α(V) + (E * logE)) = O(E * logE)
- space = O(E + V)
notes:
use DSU to track vertices in MST and check for cycles
keep track of global edge sum over all additions to the MST

1) proccess all required edges into DSU/MST
    -> if any edges would create a cycle (i.e. unable to union u and v) return -1

2) sort remaining upgradable edges by strength (desc)
    -> iterate through the list in order
    -> if an edge creates a cycle, discard it
    -> when adding a new edge to MST, store the edge weight in a stack

3) after building MST:
    -> take top k upgradable edges from the stack and add their strengths
        to the total, effectively upgrading the edge by adding it a second time to
        the global sum. (implements the greedy optimization approach)
    -> let fixed_min = weakest required edge strength
    -> let weakest_upgrade = first edge popped from stack, (weakest upgraded edge)
    -> let weakest_normal = edge at top of stack after popping all upgrades
    -> return min(fixed_min, weakest_upgrade, weakest_normal)

"""

from typing import List


class Solution:
    def union(self, u, v, root, rank) -> bool:
        A, B = self.find(u, root, rank), self.find(v, root, rank)
        if A == B:
            return False
        if rank[A] > rank[B]:
            root[B] = A
        elif rank[A] < rank[B]:
            root[A] = B
        else:
            root[B] = A
            rank[A] += rank[B]
        return True

    def find(self, u, root, rank):
        rt = root[u]
        while rt != root[rt]:
            root[rt] = root[root[rt]]
            rt = root[rt]
        return rt

    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        fixed_min, remaining = float("inf"), n - 1

        roots = [i for i in range(n)]
        ranks = [0 for i in range(n)]

        upgradable = []

        # part A
        for e in edges:
            if e[3] == 1:
                if not self.union(e[0], e[1], roots, ranks):
                    return -1
                if e[2] < fixed_min:
                    fixed_min = e[2]
                remaining -= 1
            else:
                upgradable.append(e)

        if remaining == 0:
            return fixed_min
        # part B
        # 1) sort rem edges
        upgradable.sort(key=lambda x: -x[2])

        stack = []

        # 2) complete the MST
        for idx, edge in enumerate(upgradable):
            if remaining == 0:
                break
            if not self.union(edge[0], edge[1], roots, ranks):
                continue
            stack.append(idx)
            remaining -= 1

        if remaining > 0:
            return -1

        m = len(stack)
        if m <= k:
            return min(fixed_min, 2 * upgradable[stack[-1]][2])
        else:
            return min(
                fixed_min, 2 * upgradable[stack[-1]][2], upgradable[stack[m - k - 1]][2]
            )
