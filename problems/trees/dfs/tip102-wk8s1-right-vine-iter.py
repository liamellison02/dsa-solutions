class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def right_vine(root):
    if not root: return []
    if not root.right: return [root.val]
    r, out = root, []
    while r:
        out.append(r.val)
        r = r.right
    return out
