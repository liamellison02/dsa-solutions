"""
platform: lc
id: 3661
name: maximum walls destroyed by robots
pattern: dp/linear
tags: dp,greedy,sorting,binary-search,range-query
complexity:
n = num of robots, m = num of walls
- time = O(nlogn + mlogm) = O((n + m) * log(n + m))
- space = O(n + m)
notes:
2-state dp, greedily taking max at each step:

1) sort robots and walls
2) sweep robots left-to-right with 2-state dp:
dp[0] = max walls if prev shoots left, dp[1] = max walls if prev shoots right
- at each robot, greedily partition wall breakage using range queries
- for ith robot, max breakage is:
    - max_left = max(
        curr shoots left w/ max delta + max breakage from prev shooting left,
        union of breakage from curr shooting left and prev shooting right
    )
    - max_right = max(
        prev shoots left,
        prev shoots right w/ max delta
    ) + curr shoots right w/ max delta

"""

from typing import List
from bisect import bisect_left, bisect_right


class Solution:
    def maxWalls(self, pos: List[int], dist: List[int], walls: List[int]) -> int:
        n = len(pos)

        def RQ(a, b):
            return bisect_right(walls, b) - bisect_left(walls, a)

        order = sorted(range(n), key=lambda i: pos[i])
        walls.sort()

        curr, dp = 0, [0, 0]

        first = order[0]
        right = pos[first] + dist[first]
        dp[0] = RQ(pos[first] - dist[first], pos[first])
        dp[1] = RQ(pos[first], min(
            right, pos[order[1]] - 1 if n > 1 else right))

        for i in range(1, n):
            max_left, max_right = 0, 0
            prev, curr, nxt = (
                order[i - 1],
                order[i],
                order[i + 1] if i < n - 1 else None,
            )

            dist_left = max(pos[curr] - dist[curr], pos[prev] + 1)

            if nxt is not None:
                dist_right = min(pos[curr] + dist[curr], pos[nxt] - 1)
            else:
                dist_right = pos[curr] + dist[curr]

            meet = max(dist_left, min(
                pos[prev] + dist[prev], pos[curr] - 1) + 1)

            max_left = max(
                RQ(dist_left, pos[curr]) + dp[0], RQ(meet, pos[curr]) + dp[1]
            )
            max_right = RQ(pos[curr], dist_right) + max(dp[0], dp[1])

            dp[0], dp[1] = max_left, max_right

        return max(dp[0], dp[1])
