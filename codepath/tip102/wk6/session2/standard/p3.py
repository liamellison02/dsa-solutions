class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next
    
def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=" -> " if current.next else "\n")
        current = current.next

def partition(suspect_ratings, threshold):
    head = high = Node(0)
    prev, curr = suspect_ratings, suspect_ratings.next
    
    while curr:
        if curr.val > threshold:
            high.next = curr
            prev.next = curr.next
            curr = prev.next
        else:
            curr = curr.next
    
    return head.next
