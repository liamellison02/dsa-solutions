"""
platform: lc
id: 297
name: serialize and deserialize binary tree
pattern: trees/construct
tags: binary-tree,tree,design,construction,dfs,bfs,string
complexity:
- time = O(n)
- space = O(n)
notes:
construct & destruct using DFS or BFS
"""

from lib.py.structures import TreeNode


class Codec:
    def serialize(self, root: TreeNode):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        res = []

        def dfs(node):
            if not node:
                res.append("N")
            else:
                res.append(str(node.val))
                dfs(node.left)
                dfs(node.right)

        dfs(root)
        return ",".join(res)

    def deserialize(self, data: TreeNode):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        nodes = data.split(",")
        self.i = 0

        def dfs():
            if nodes[self.i] == "N":
                self.i += 1
                return None

            node = TreeNode(int(nodes[self.i]))
            self.i += 1

            node.left = dfs()
            node.right = dfs()

            return node

        return dfs()
