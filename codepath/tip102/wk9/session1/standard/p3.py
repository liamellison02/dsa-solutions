# Time: O(n), Space: O(h)
class TreeNode():
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def max_tiers(cake):
    if not cake: return 0
    return 1 + max(max_tiers(cake.left), max_tiers(cake.right))
