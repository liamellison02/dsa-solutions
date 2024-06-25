import collections
import string
from typing import List, Dict, Tuple, Any, Union, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    # 1. Two Sum
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Hashmap solution: O(n) time complexity, O(n) space complexity
        hashMap = {}
        index = 0
        diff = 0
        
        for item in nums:
            diff = target - item
            if diff in hashMap:
                return [hashMap[diff], index]
            hashMap[item] = index
            index += 1

    # 2. Valid Parentheses
    def isValid(self, s: str) -> bool:
        # Stack solution: O(n) time complexity, O(n) space complexity
        opens = [ '(', '{', '[' ]
        closes = [ ')', '}', ']' ]
        stack = []
        
        for v in s:
            if v in opens:
                stack.append(v)
            elif v in closes:
                if len(stack)==0:
                    return False
                if closes.index(v) == opens.index(stack[len(stack)-1]):
                    stack.pop()
                else:
                    return False
            else:
                return False

        return True if len(stack) == 0 else False

    # 3. Merge Two Sorted Lists
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # O(n) time complexity, O(1) space complexity
        head = ListNode()
        tail = head

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        if list1:
            tail.next = list1
        else:
            tail.next = list2
        
        return head.next
    
    # 4. Best Time to Buy and Sell Stock
    def maxProfit(self, prices: List[int]) -> int:
        # Two pointers solution: O(n) time complexity, O(1) space complexity
        profit, ptr1, ptr2 = 0, 0, 1

        while ptr2 < len(prices):
            if prices[ptr2] < prices[ptr1]:
                ptr1 = ptr2
                ptr2 += 1
            else:
                if prices[ptr2] - prices[ptr1] > profit:
                    profit = prices[ptr2] - prices[ptr1]
                ptr2 += 1

        return profit
        
    # 5. Valid Palindrome
    def isPalindrome(self, s: str) -> bool:
        # Two pointers solution: O(n/2) = O(n) time complexity, O(1) space complexity
        lb, rb = 0, len(s) - 1
        while lb <= rb:
            if s[lb].isalnum() and s[rb].isalnum():
                if s[lb].upper() != s[rb].upper():
                    return False
                else:
                    lb += 1
                    rb -= 1
            else:
                if not s[lb].isalnum():
                    lb +=1
                if not s[rb].isalnum():
                    rb -=1
        
        return True
    
    # 6. Invert Binary Tree
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root
    
    # 7. Vaild Anagram
    def isAnagram(self, s: str, t: str) -> bool:
        hm = dict.fromkeys(string.ascii_lowercase, 0)
        total = 0
        
        for c in s:
            hm[c]+=1
            total+=1
        for i in t:
            if hm[i] > 0:
                hm[i]-=1
                total-=1
            else:
                return False
        
        return True if total == 0 else False
    
    # 8. Binary Search
    def binarySearch(self, nums: List[int], target: int) -> int:
        lb, rb, mid = 0, len(nums)-1, 0
        while lb <= rb:
            mid = (lb + rb) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                lb = mid + 1
            else:
                rb = mid - 1
        return -1


if __name__ == '__main__':
    # Initial Test Cases
    sol = Solution()
    print(sol.twoSum([2,7,11,15], 9)) # [0, 1]
    print(sol.isValid("()")) # True
    print(sol.mergeTwoLists(ListNode(1, ListNode(2, ListNode(4))), ListNode(1, ListNode(3, ListNode(4))))) # 1 -> 1 -> 2 -> 3 -> 4 -> 4
    print(sol.maxProfit([7,1,5,3,6,4])) # 5
    print(sol.isPalindrome("Az a")) # True
    print(sol.invertTree(TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7, TreeNode(6), TreeNode(9)))).val) # 4
    print(sol.isAnagram("anagram", "nagaram")) # True
    print(sol.binarySearch([-1,0,3,5,9,12], 9)) # 4
    