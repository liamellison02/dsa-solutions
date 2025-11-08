class TreeNode:
    def __init__(self, key, val, left=None, right=None):
        self.key = key
        self.val = val
        self.left = left
        self.right = right

def pick_plant(inventory, budget):
    r, ans = inventory, None
    while r:
        if r.key < budget:
            ans = r
            r = r.right
        else:
            r = r.left
    return None if not ans else ans.val
