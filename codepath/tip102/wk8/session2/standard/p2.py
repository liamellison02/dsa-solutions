class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def find_flower(inventory, name):
    r = inventory
    while r:
        if r.val == name: return True
        r = r.left if name < r.val else r.right
    return False
