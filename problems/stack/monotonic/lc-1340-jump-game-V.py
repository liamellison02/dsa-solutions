"""
platform: lc
id: 1340
name: jump game V
difficulty: hard
url: https://leetcode.com/problems/jump-game-v/
pattern: stack/monotonic
tags: segment-tree,rmq,range-query,sorting,stack,monotonic-stack,dp
complexity:
- time = O(nlogn)
- space = O(n)
notes:
dp[i] = max idxes visitable starting from i = 1 + max(dp[j]) over reachable j

you can only land on strictly shorter bars within distance d
and you can't jump over a bar that's >= arr[i]

solution:
process indices in increasing height order
when we reach i -> every reachable target is shorter + finalized

monotonic stacks find the nearest blocking bar (height >= arr[i]) on each side:
  L[i] = nearest taller-or-equal index to the left   (-1 if none)
  R[i] = nearest taller-or-equal index to the right  (n if none)
so the reachable windows are:
  right = [i+1, min(i+d, R[i]-1)]
  left  = [max(i-d, L[i]+1), i-1]
every bar inside these windows is strictly shorter (stk stops at the first >=)
so all of them are legal jumps

need max dp over windows -> iterative seg tree (point update + range max)
- walk i in sorted-by-height order
- query both windows
- dp[i] = max(lm,rm) + 1
update the tree at i

return max(dp).
"""

from typing import List


class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)

        stk, L, R = [], [-1 for _ in range(n)], [n for _ in range(n)]
        for i in range(n):
            while stk and arr[stk[-1]] < arr[i]:
                stk.pop()
            if stk:
                L[i] = stk[-1]
            stk.append(i)

        stk = []
        for i in range(n - 1, -1, -1):
            while stk and arr[stk[-1]] < arr[i]:
                stk.pop()
            if stk:
                R[i] = stk[-1]
            stk.append(i)

        sz = 1
        while sz < n:
            sz <<= 1
        st = [0 for _ in range(2 * sz)]

        def update(p, v):
            p += sz
            st[p] = v
            p >>= 1
            while p:
                st[p] = max(st[2 * p], st[2 * p + 1])
                p >>= 1

        def query(l, r):
            if l > r:
                return 0
            res = 0
            l += sz
            r += sz + 1
            while l < r:
                if l & 1:
                    if st[l] > res:
                        res = st[l]
                    l += 1
                if r & 1:
                    r -= 1
                    if st[r] > res:
                        res = st[r]
                l >>= 1
                r >>= 1
            return res

        dp = [0 for _ in range(n)]
        for i in sorted(range(n), key=arr.__getitem__):
            rm = query(i + 1, min(i + d, R[i] - 1))
            lm = query(max(i - d, L[i] + 1), i - 1)

            dp[i] = max(rm, lm) + 1
            update(i, dp[i])

        return max(dp)
