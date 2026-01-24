"""
platform: lc
id: 226
name: invert-binary-tree
pattern: trees
tags: tree,recursion,dfs
complexity:
- time = O(n)
- space = O(h) where h is tree height
notes:
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root
