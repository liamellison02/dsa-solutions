"""
platform: lc
id: 141
name: linked-list-cycle
pattern: linked_list
tags: linked-list,fast-slow-pointers
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
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        tortoise = hare = head

        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next

            if tortoise == hare:
                return True

        return False
