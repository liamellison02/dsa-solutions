from typing import List


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def merge(l1, l2):
    head =  ListNode()
    curr = head

    while l1 and l2:
        if l1.val < l2.val:
            curr.next, l1 = l1, l1.next
        else:
            curr.next, l2 = l2, l2.next
        curr = curr.next
    curr.next = l1 or l2

    return head.next


def merge_k_lists(lists: List[ListNode]) -> ListNode:
    while len(lists) > 0:
        merged = []
        for i in range(0, len(lists), 2):
            l1 = lists[i]
            l2 = lists[i+1] if i+1 < len(lists) else None
            merged.append(merge(l1, l2))
        lists = merged
    return lists[0]


def merge_k_lists_arr(nodes: List[ListNode]) -> ListNode:
    arr = []
    for n in nodes:
        while n:
            arr.append(n.val)
            n = n.next
    return sorted(arr)
