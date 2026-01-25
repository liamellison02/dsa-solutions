# Time: O(n), Space: O(n)
from collections import deque

class TreeNode():
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def sweet_difference(chocolates):
    if not chocolates: return []
    
    q = deque([chocolates])
    res = []
    
    while q:
        mn = float("inf")
        mx = float("-inf")
        for _ in range(len(q)):
            n = q.popleft()
            v = n.val
            mn = min(mn, v)
            mx = max(mx, v)

            if n.left: q.append(n.left)
            if n.right: q.append(n.right)
        
        res.append(mx - mn)
    
    return res
