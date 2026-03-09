"""
platform: lc
id: 124
name: binary tree maximum path sum
pattern: trees/dfs
tags: dfs,max-path,max,binary-tree,recursion,post-order,trees
complexity:
- time = O(n)
- space = O(n)
notes:
dfs, tracking max path that goes through each node.

must consider the edge case where the max path sum crosses
over a parent, and to not calculate that path sum as the maxPathSum
that goes THROUGH the parent back up to it's parent, b/c you can
only use each edge once.
"""

from typing import *
from collections import defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float("-inf")
        maxPath = defaultdict(int)

        def dfs(node):
            if not node:
                return

            dfs(node.right)
            dfs(node.left)

            maxRight = maxPath[node.right] if node.right else 0
            maxLeft = maxPath[node.left] if node.left else 0
            maxPath[node] = node.val + max(maxRight, maxLeft, 0)

            self.res = max(self.res, maxLeft + maxRight + node.val, maxPath[node])

        dfs(root)
        return self.res
