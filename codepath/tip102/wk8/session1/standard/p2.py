class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def calculate_yield(root):
    a = {'+': lambda x,y:x+y, '-':lambda x,y:x-y, '*':lambda x,y:x*y, '/':lambda x,y:x/y}
    return a[root.val](root.left.val, root.right.val)
