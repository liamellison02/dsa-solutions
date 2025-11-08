class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def non_bst_find_flower(root, name):
    if root is None:
        return False
    if root.val == name:
        return True
    return non_bst_find_flower(root.left, name) or non_bst_find_flower(root.right, name)
