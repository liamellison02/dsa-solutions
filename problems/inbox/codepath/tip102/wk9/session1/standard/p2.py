# Time: O(n), Space: O(n)
from collections import deque

class Puff():
    def __init__(self, flavor, left=None, right=None):
        self.val = flavor
        self.left = left
        self.right = right

def print_design(design):
    if not design:
        print([])
        return
    
    q = deque([design])
    r = []
    
    while q:
        n = q.popleft()
        r.append(n.val)
        if n.left: q.append(n.left)
        if n.right: q.append(n.right)
    
    print(r)
