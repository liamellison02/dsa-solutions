from typing import *


class ListNode:
    def __init__(self, val: int = 0, next: "ListNode | None" = None):
        self.val = val
        self.next = next

    def __repr__(self) -> str:
        parts = []
        cur = self
        while cur:
            parts.append(str(cur.val))
            cur = cur.next
        return " -> ".join(parts)


class TreeNode:
    def __init__(
        self,
        val: int = 0,
        left: "TreeNode | None" = None,
        right: "TreeNode | None" = None,
    ):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return f"TreeNode({self.val})"


# --- builders ---


def build_linked_list(vals: list[int]) -> ListNode | None:
    """Build a linked list from a list of values. Returns head."""
    if not vals:
        return None
    head = ListNode(vals[0])
    cur = head
    for v in vals[1:]:
        cur.next = ListNode(v)
        cur = cur.next
    return head


def build_tree(vals: list[int | None]) -> TreeNode | None:
    """Build a binary tree from a level-order list (LeetCode format).
    None represents missing nodes. Returns root."""
    if not vals or vals[0] is None:
        return None
    root = TreeNode(vals[0])
    queue = [root]
    i = 1
    while i < len(vals):
        node = queue.pop(0)
        if i < len(vals) and vals[i] is not None:
            node.left = TreeNode(vals[i])
            queue.append(node.left)
        i += 1
        if i < len(vals) and vals[i] is not None:
            node.right = TreeNode(vals[i])
            queue.append(node.right)
        i += 1
    return root


def linked_list_to_list(head: ListNode | None) -> list[int]:
    """Convert a linked list back to a Python list."""
    result = []
    cur = head
    while cur:
        result.append(cur.val)
        cur = cur.next
    return result


def tree_to_list(root: TreeNode | None) -> list[int | None]:
    """Convert a binary tree back to level-order list (LeetCode format)."""
    if not root:
        return []
    result = []
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)
    while result and result[-1] is None:
        result.pop()
    return result
