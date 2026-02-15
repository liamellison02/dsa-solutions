"""
platform: lc
id: 19
name: remove-nth-node-from-end
difficulty: medium
url: https://leetcode.com/problems/remove-nth-node-from-end/
pattern: linked_list
tags: linked-list,two-pointers
complexity:
- time = O(n)
- space = O(1)
notes: advance a runner pointer n steps ahead, then move both runner and walker together; when runner hits the end, walker is right before the target node
"""
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return head

        runner = head
        walker = ListNode()
        walker.next = head
        gap = n

        while gap > 0:
            if not runner.next:
                if gap == 1:
                    head = head.next
                    return head
            runner = runner.next
            gap -= 1

        while runner:
            walker = walker.next
            runner = runner.next

        walker.next = walker.next.next
        return head
