"""
platform: lc
id: 110
name: balanced-binary-tree
pattern: trees/dfs
tags: tree,dfs,recursion
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
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.balanced = True

        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            if (abs(left - right) > 1):
                self.balanced= False

            return max(left, right) + 1

        dfs(root)
        return self.balanced
