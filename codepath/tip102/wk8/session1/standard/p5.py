class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def count_leaves(root):
    if not root: return 0
    if not root.left and not root.right: return 1
    return count_leaves(root.left) + count_leaves(root.right)
