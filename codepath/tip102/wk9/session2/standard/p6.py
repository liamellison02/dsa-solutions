# Time: O(n), Space: O(n)
from collections import deque

class TreeNode():
    def __init__(self, order, left=None, right=None):
        self.val = order
        self.left = left
        self.right = right

def find_next_order(order_tree, order):
    if not order_tree: return None
    
    q = deque([order_tree])
    
    while q:
        sz = len(q)
        for i in range(sz):
            n = q.popleft()
            if n is order: return None if i == sz - 1 else q[0]
            
            if n.left: q.append(n.left)
            if n.right: q.append(n.right)

    return None
