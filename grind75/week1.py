import string
from typing import List, Dict, Tuple, Any, Union, Optional
from resources import ListNode, TreeNode

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
    
    # 9. Flood Fill
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows, cols, color = len(image)-1, len(image[0])-1, image[sr][sc]
        
        def fill(sr, sc):
            if not (0 <= sr <= rows and 0 <= sc <= cols):
                return
            if image[sr][sc] != color or image[sr][sc] == newColor:
                return
            else:
                image[sr][sc] = newColor
                fill(sr+1,sc)
                fill(sr,sc+1)
                fill(sr-1,sc)
                fill(sr,sc-1)
        
        fill(sr, sc)
        return image
    
    # 10. Lowest Common Ancestor of a Binary Search Tree
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        while root:
            if root.val < p.val and root.val < q.val:
                root = root.right
            elif root.val > p.val and root.val > q.val:
                root = root.left
            else:
                return root
            
    # 11. Balanced Binary Tree
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.balanced = True

        def dfs(root):         
            if not root: 
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            if (abs(left - right) > 1):
                self.balanced= False
                
            return max(left, right) + 1
        
        dfs(root)
        return self.balanced
    
    # 12. Linked List Cycle
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        tortoise = hare = head

        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next

            if tortoise == hare: 
                return True
                
        return False
    
    # If you want to make it slightly more efficient, you can use try-except block:
    # def hasCycle(self, head: Optional[ListNode]) -> bool:
    #     try:
    #         tortoise = head
    #         hare = head.next
    #         while tortoise is not hare:
    #             tortoise = tortoise.next
    #             hare = hare.next.next
    #         return True
    #     except:
    #         return False

    # 13. Remove Nth Node From End of List
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
        # handles null list, single node list if n > 1, and 2-node list if n > 2
            return head

        runner = head
        # walker starts as dummy node with next pointing to head so when we walk up
        # the LL, we can stop right before the n-before-last node and remove the
        # pointer to our target node
        walker = ListNode()
        walker.next = head
        gap = n # counter variable for our gap between walker and runner

        while gap > 0:
            if not runner.next:
                # handles when n > len(list) and n == len(list)
                if gap == 1:
                    head = head.next
                    return head
            runner = runner.next
            gap -= 1

        while runner:
            # walks up list until runner reaches end
            walker = walker.next
            runner = runner.next

        walker.next = walker.next.next # removes the target node
        return head

    # 14. Reverse Linked List
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr, prev, temp = head, None, None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev
    
    # 15. Top K Frequent Elements
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        countMap = {}
        freq = [[] for i in range(len(nums) + 1)]

        for n in nums:
            countMap[n] = countMap.get(n, 0) + 1
        for n, c in countMap.items():
            freq[c].append(n)
        
        res = []
        for i in range(len(freq)-1, 0, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
                
    # 16. Encode and Decode Strings
    def encode(self, strs: List[str]) -> str:
        ret = ""
        for s in strs:
            ret += str(len(s)) + '#' + s
        return ret

    def decode(self, s: str) -> List[str]:
        temp = ""
        currDelim = 0
        i = 0
        retArr = []
        while i < len(s):
            if currDelim == 0:
                while s[i] != "#":
                    temp += s[i]
                    i += 1
                currDelim = int(temp)
                if currDelim == 0:
                    retArr.append("")
                temp = ""
                i += 1
            else:
                retArr.append(s[i:i+currDelim])
                i += currDelim
                currDelim = 0
        
        return retArr
    
    # 17. Longest Substring Without Repeating Characters
    def lengthOfLongestSubstring(self, s: str) -> int:

        unique, longest, lb = set(), 0, 0
    
        for rb in range(len(s)):
            while s[rb] in unique:
                unique.remove(s[lb])
                lb += 1
            unique.add(s[rb])
            longest = max(longest, rb-lb+1)

        return longest
    
    # 18. Longest Palindromic Substring
    def longestPalindrome(s: str):
        if len(s) == 1:
            return s

        if s == s[::-1]:
            return s

        longest = ""
        curr = ""
        temp = ""
        for i in range(len(s)-1, -1, -1):
            curr = ""
            for j in range(len(s)):
                if i == j:
                    if len(curr) == 0:
                        curr = s[i]
                else:
                    temp = s[j:i+1]
                    if temp == temp[::-1]:
                        if len(temp) > len(curr):
                            curr = temp

            if len(curr) > len(longest):
                longest = curr


        return longest
    
    # 19. Product of Array Except Self
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        products = [0 for n in range(len(nums))]
        totalProduct = 1
        numZeroes = 0
        zeroIndex = None
        for i in range(len(nums)):
            if nums[i] != 0:
                totalProduct *= nums[i]
            elif numZeroes < 1:
                numZeroes += 1
                zeroIndex = i
            else:
                return products
        
        if numZeroes == 1:
            products[zeroIndex] = totalProduct
            return products

        for j in range(len(nums)):
            products[j] = (totalProduct)//nums[j]
        
        return products


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
    print(sol.floodFill([[1,1,1],[1,1,0],[1,0,1]], 1, 1, 2)) # [[2,2,2],[2,2,0],[2,0,1]]
    print(sol.lowestCommonAncestor(TreeNode(6, TreeNode(2, TreeNode(0), TreeNode(4, TreeNode(3), TreeNode(5))), TreeNode(8, TreeNode(7), TreeNode(9))), TreeNode(2), TreeNode(8)).val) # 6
    print(sol.isBalanced(TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7))))) # True
