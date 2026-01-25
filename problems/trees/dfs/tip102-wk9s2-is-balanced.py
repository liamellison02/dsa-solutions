# Time: O(n), Space: O(h)
class TreeNode():
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def is_balanced(display):
    def f(n):
        if not n: return 0
        
        l = f(n.left)
        if l == -1: return -1
        
        r = f(n.right)
        if r == -1 or abs(l - r) > 1: return -1
        
        return 1 + max(l, r)
    
    return f(display) != -1
