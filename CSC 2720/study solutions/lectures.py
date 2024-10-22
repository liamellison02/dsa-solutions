import collections
import math
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Graphs problem: Determine pre-requisites for courses
def courseOrder(pr: list):
    adcolList = collections.defaultdict(list) # default value for each key is an empty list
    for c, p in pr:
        adcolList[c].append(p)
    visited, c_check = set(), set() # Space complexity: O(n)
    TO = [] # topilogically ordered list
    
    def dfs(crse):
        if crse in visited:
            return True
        if crse in c_check:
            return False
        for i in adcolList[crse]:
            if not dfs(i):
                return False
        visited.add(crse)
        c_check.add(crse)
        TO.append(crse)
        return True
    
    for c in adcolList:
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
    




def createSubBoxes(n, x0, x1, y0, y1):
    rows, cols, boxes = math.ceil(math.sqrt(n)), math.ceil(math.sqrt(n)), []

    boxWidth = (x1 - x0) // cols
    boxHeight = (y1 - y0) // rows

    for row in range(rows):
        for col in range(cols):
            boxes.append((x0 + col*boxWidth, x0 + (col*boxWidth)+boxWidth, y0 + row*boxHeight, y0 + (row*boxHeight)+boxHeight))
    
    return boxes


def main():
    print(createSubBoxes(9, 0, 9, 0, 9))

if __name__ == "__main__":
    main()
    

