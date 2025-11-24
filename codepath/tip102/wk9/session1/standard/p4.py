# Time: O(n), Space: O(n)
from collections import deque

class TreeNode():
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def max_tiers(cake):
    if not cake: return 0
    
    q = deque([cake])
    d = 0
    
    while q:
        d += 1
        for _ in range(len(q)):
            n = q.popleft()
            if n.left: q.append(n.left)
            if n.right: q.append(n.right)

    return d
