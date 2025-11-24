# Time: O(n), Space: O(h)
class TreeNode():
    def __init__(self, flavor, left=None, right=None):
        self.val = flavor
        self.left = left
        self.right = right

def can_rearrange_orders(order1, order2):
    if not order1 and not order2: return True
    if not order1 or not order2 or order1.val != order2.val: return False
    
    return (
        can_rearrange_orders(order1.left, order2.left)
        and can_rearrange_orders(order1.right, order2.right)
    ) or (
        can_rearrange_orders(order1.left, order2.right)
        and can_rearrange_orders(order1.right, order2.left)
    )
