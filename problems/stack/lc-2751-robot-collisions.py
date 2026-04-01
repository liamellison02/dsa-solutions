"""
platform: lc
id: 2751
name: robot collisions
pattern: stack
tags: stack,sorting,simulation
complexity:
- time = O(nlogn)
- space = O(n)
notes:
sort the bots based on position, (add an init idx for res order)
iterate through each position in ascending order, using stack for
incoming bots from the left for collision checks

tuple:
(starting position, health, direction, input idx)
0 = starting position
1 = health
2 = direction
3 = input idx

"""

from typing import List


class Solution:
    def survivedRobotsHealths(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        n = len(positions)
        stream = sorted(zip(positions, healths, directions, range(n)))

        escaped, incoming = [], []

        for i, v in enumerate(stream):
            pos, health, direction, idx = v[0], v[1], v[2], v[3]
            if direction == "L":
                while incoming and health > 0:
                    if incoming[-1][1] > health:
                        health = 0
                        incoming[-1][1] -= 1
                        break
                    elif incoming[-1][1] == health:
                        health = 0
                    else:
                        health -= 1
                    incoming.pop()
                if not incoming and health > 0:
                    escaped.append([pos, health, direction, idx])
            else:
                incoming.append([pos, health, direction, idx])

        if incoming:
            escaped.extend(incoming)

        return [bot[1] for bot in sorted(escaped, key=lambda x: x[3])]

    def survivedRobotsHealthsMicroOptimized(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        n = len(positions)
        idx = sorted(range(n), key=positions.__getitem__)

        stk = []
        for i in idx:
            if directions[i] == "L":
                while stk and healths[i] > 0:
                    top = stk[-1]
                    if healths[top] > healths[i]:
                        healths[top] -= 1
                        healths[i] = 0
                        break
                    elif healths[top] < healths[i]:
                        healths[i] -= 1
                    else:
                        healths[i] = 0

                    healths[top] = 0
                    stk.pop()
            else:
                stk.append(i)

        return [h for h in healths if h > 0]
