"""
platform: lc
id: 235
name: lowest-common-ancestor-of-bst
pattern: trees/lca
tags: bst,tree
complexity:
- time = O(h) where h is tree height
- space = O(1)
notes:
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        while root:
            if root.val < p.val and root.val < q.val:
                root = root.right
            elif root.val > p.val and root.val > q.val:
                root = root.left
            else:
                return root
