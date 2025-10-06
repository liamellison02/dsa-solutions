class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def print_linked_list(head):
    curr = head
    while curr:
        print(curr.value, end=" -> " if curr.next else "\n")
        curr = curr.next

def add_first(head, task):
    return Node(task, head)
