"""
platform: lc
id: 1373
name: maximum sum bst in binary tree
pattern: trees/dfs
tags: dfs,bst,binary-tree,recursion,post-order,trees
complexity:
- time = O(n)
- space = O(n)
notes:
global curr max subtree sum tracker/variable
recursively DFS to find if subtree is BST
if subtree is BST and subtree sum > global curr max:
    global curr max = subtree sum
return global max
"""

from typing import *


class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.res = 0

        def dfs(n):
            """
            returns [isBST, sum of sub of all children + root]
            """
            if not n:
                return (True, 0, float("inf"), float("-inf"))

            lb, lsum, lmin, lmax = dfs(n.left)
            rb, rsum, rmin, rmax = dfs(n.right)

            if lb and rb and lmax < n.val < rmin:
                s = lsum + rsum + n.val
                self.res = max(self.res, s)
                return (True, s, min(lmin, n.val), max(rmax, n.val))

            return (False, 0, 0, 0)

        dfs(root)
        return self.res
