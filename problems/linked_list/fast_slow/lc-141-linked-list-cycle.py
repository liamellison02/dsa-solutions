"""
platform: lc
id: 141
name: linked-list-cycle
difficulty: easy
url: https://leetcode.com/problems/linked-list-cycle/
pattern: linked_list/fast_slow
tags: linked-list,fast-slow-pointers
complexity:
- time = O(n)
- space = O(1)
notes: Floyd's cycle detection: slow moves 1 step, fast moves 2 steps; they meet iff a cycle exists
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
