import collections
from typing import List, Dict, Tuple, Any, Union


class Solution:
    
    # 1. Two Sum
    def twoSum(self, nums: List[int], target: int) -> List[int]:
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
