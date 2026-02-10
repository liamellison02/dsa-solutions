class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def right_vine(root):
    if not root: return []
    if not root.right: return [root.val]
    return [root.val] + right_vine(root.right)
