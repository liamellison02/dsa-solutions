class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def print_linked_list(head):
    curr = head
    while curr:
        print(curr.value, end=" -> " if curr.next else "\n")
        curr = curr.next

def delete_tail(head):
    if not head or not head.next:
        return None
    c = head
    while c.next.next:
        c = c.next
    c.next = None
    return head
