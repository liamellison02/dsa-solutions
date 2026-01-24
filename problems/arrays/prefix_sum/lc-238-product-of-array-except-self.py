"""
platform: lc
id: 238
name: product-of-array-except-self
pattern: arrays/prefix_sum
tags: prefix,product
complexity:
- time = O(n)
- space = O(1) excluding output
notes: handles zeros specially
"""
from typing import List

class Solution:
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
