# Time: O(n), Space: O(n)
from collections import deque

class TreeNode():
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def sum_each_days_orders(orders):
    if not orders: return []
    
    q = deque([orders])
    res = []
    
    while q:
        s = 0
        for _ in range(len(q)):
            n = q.popleft()
            s += n.val
            if n.left: q.append(n.left)
            if n.right: q.append(n.right)
        res.append(s)
    
    return res
