# Time: O(n), Space: O(h)
class TreeNode():
    def __init__(self, quantity, left=None, right=None):
        self.val = quantity
        self.left = left
        self.right = right

def merge_orders(order1, order2):
    if not order1 and not order2: return None
    if not order1: return order2
    if not order2: return order1

    order1.val += order2.val
    order1.left = merge_orders(order1.left, order2.left)
    order1.right = merge_orders(order1.right, order2.right)
    
    return order1
