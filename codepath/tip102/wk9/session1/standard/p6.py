# Time: O(n), Space: O(n)
from collections import deque

class TreeNode():
    def __init__(self, flavor, left=None, right=None):
        self.val = flavor
        self.left = left
        self.right = right

def zigzag_icing_order(cupcakes):
    if not cupcakes: return []
    
    q = deque([cupcakes])
    r, f = [], True
    while q:
        lvl = []
        for _ in range(len(q)):
            n = q.popleft()
            lvl.append(n.val)
            if n.left: q.append(n.left)
            if n.right: q.append(n.right)

        if not f: lvl.reverse()
        
        r.extend(lvl)
        f = not f
    
    return r
