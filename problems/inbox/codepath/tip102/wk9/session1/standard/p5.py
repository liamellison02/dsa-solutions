# Time: O(n), Space: O(h)
class TreeNode():
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def can_fulfill_order(inventory, order_size):
    if not inventory: return False
    if not inventory.left and not inventory.right: return inventory.val == order_size
    
    t = order_size - inventory.val
    return can_fulfill_order(inventory.left, t) or can_fulfill_order(inventory.right, t)
