import collections
from typing import Optional
from resources import TreeNode

# Graphs problem: Determine pre-requisites for courses
def courseOrder(pr: list):
    adjList = collections.defaultdict(list) # default value for each key is an empty list
    for c, p in pr:
        adjList[c].append(p)
    visited, c_check = set(), set() # Space complexity: O(n)
    TO = [] # topilogically ordered list
    
    def dfs(crse):
        if crse in visited:
            return True
        if crse in c_check:
            return False
        for i in adjList[crse]:
            if not dfs(i):
                return False
        visited.add(crse)
        c_check.add(crse)
        TO.append(crse)
        return True
    
    for c in adjList:
        if not dfs(c):
            return []   
            
    return TO

# Question 3: 3rd smallest element in BST
def thirdSmallest(self, root: Optional[TreeNode]):
    if not root:
        return "Null tree given"
    if not root.left or not root.right:
        return "Tree has less than 3 nodes"
    
    counter = 3
    stack = collections.deque()
    curr = root
    while curr or stack:
        if curr:
            stack.append(curr)
            curr = curr.left
        else:
            curr = stack.pop()
            counter -= 1
            if counter == 0:
                return curr.val
            curr = curr.right
    
    return self.res
    
