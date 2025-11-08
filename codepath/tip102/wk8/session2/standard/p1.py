class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def count_odd_splits(root):
    if not root: return 0
    return (root.val % 2) + count_odd_splits(root.left) + count_odd_splits(root.right)
