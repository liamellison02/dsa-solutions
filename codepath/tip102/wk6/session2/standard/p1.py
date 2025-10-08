class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def is_circular(clues):
    # Time complexity = O(n), where n = # of nodes in list
    head = clues
    clues = clues.next
    
    while clues:
        if clues == head:
            return True
        clues = clues.next
    
    return False
        