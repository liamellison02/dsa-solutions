# Time: O(n), Space: O(h)
class TreeNode():
    def __init__(self, order_size, left=None, right=None):
        self.val = order_size
        self.left = left
        self.right = right

def larger_order_tree(orders):
    def f(n, s):
        if not n: return s
        
        s = f(n.right, s)
        n.val += s
        s = n.val
        
        return f(n.left, s)
    
    f(orders, 0)
    return orders
