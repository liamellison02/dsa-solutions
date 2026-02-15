"""
platform: lc
id: 235
name: lowest-common-ancestor-of-bst
difficulty: medium
url: https://leetcode.com/problems/lowest-common-ancestor-of-bst/
pattern: trees/lca
tags: bst,tree
complexity:
- time = O(h) where h is tree height
- space = O(1)
notes: BST property means both p and q are on the same side until they split; the first node where p and q diverge to different subtrees is the LCA
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
