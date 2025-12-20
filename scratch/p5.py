"""

Q5:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You have a watch, but it is not set correctly. 
How many bus arrivals do you need to witness to determine the current time?

Print your answer to stdout.

"""

import sys
from collections import defaultdict

# (pigeonhole-esque)
# ans = worst case scenario = longest unique delta sequence

t = sorted(map(int, sys.stdin.read().strip()))

d = [t[i]-t[i-1] for i in range(1, len(t))]

n = len(d)
m = [0]*n

for l in range(1, n+1):
    c = defaultdict(int)

    # count all l-length windows
    for i in range(n-l+1):
        c[tuple(d[i:i+l])] += 1

    # find first unique window at i
    for i in range(n-l+1):
        if m[i]==0 and c[tuple(d[i:i+l])] == 1:
            m[i] = l


ans = 0
for i in range(n):
    l = m[i] or (n - i)
    if l > ans:
        ans = l

print(ans + 1)
