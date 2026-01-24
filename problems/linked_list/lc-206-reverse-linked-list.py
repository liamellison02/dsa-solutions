"""
platform: lc
id: 206
name: reverse-linked-list
pattern: linked_list
tags: linked-list,iterative
complexity:
- time = O(n)
- space = O(1)
notes:
"""
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr, prev, temp = head, None, None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev
