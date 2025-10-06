class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def print_linked_list(head):
    curr = head
    while curr:
        print(curr.value, end=" -> " if curr.next else "\n")
        curr = curr.next

def halve_list(head):
    c = head
    while c:
        c.value /= 2
        c = c.next
    return head
