"""
platform: lc
id: 236
name: lowest common ancestor of a binary tree
pattern: trees/lca
tags: dfs,trees,binary-tree,lca
complexity:
- time = O(n)
- space = O(h) = O(n)
notes:
dfs, returning either LCA of one or both all the way up
"""

from typing import *


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        def dfs(node, p, q):
            if not node:
                return node
            if node == p or node == q:
                return node

            left = dfs(node.left, p, q)
            right = dfs(node.right, p, q)

            if left and right:
                return node

            return right if right else left

        return dfs(root, p, q)
