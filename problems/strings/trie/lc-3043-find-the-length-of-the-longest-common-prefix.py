"""
platform: lc
id: 3043
name: find the length of the longest common prefix
pattern: strings/trie
tags: trie,prefix-tree,prefix,bfs,hashing,hashmap,hashtable,map

complexity:
m = len(arr1)
n = len(arr2)
N = m + n
max N = 100,000
L = max arr1[i], arr2[i] = 100,000,000 = 10^8
- time = O(N * L)
- space = O(N * L)

notes:
trie + bfs solution
1) create tries for arr1 & arr2
2) bfs through all elements in the trie with less children/starting chars
    -> this trie is the "anchor" trie

bfs(nodeA, nodeB, lvl):
- nodeA -> current node in anchor trie
- nodeA -> current node in secondary trie
- lvl -> current level in BFS/length of prefix

"""

from collections import deque
from typing import List


class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        A, B = dict(), dict()

        # 1) build tries
        for n in arr1:
            curr = A
            for b in str(n).encode():
                d = b - 48
                if d not in curr:
                    curr[d] = dict()
                curr = curr[d]

        for n in arr2:
            curr = B
            for b in str(n).encode():
                d = b - 48
                if d not in curr:
                    curr[d] = dict()
                curr = curr[d]

        # 2) bfs through matches
        if len(B) < len(A):
            A, B = B, A

        res = 0
        q = deque()
        for p, c in A.items():
            if p in B:
                q.append((c, B[p], 1))

        while q:
            a, b, lvl = q.popleft()
            if lvl > res:
                res = lvl

            for p, c in a.items():
                if p in b:
                    q.append((c, b[p], lvl + 1))

        return res
