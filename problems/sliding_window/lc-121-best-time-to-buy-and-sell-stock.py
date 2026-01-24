"""
platform: lc
id: 121
name: best-time-to-buy-and-sell-stock
pattern: sliding_window
tags: two-pointers,greedy
complexity:
- time = O(n)
- space = O(1)
notes:
"""
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
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
