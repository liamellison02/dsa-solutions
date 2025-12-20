"""

Q3:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You left your watch at home.
You've just observed 2 buses arriving 4 units of time apart, what is the expected time until the next bus arrives?

Round your answer down to the lowest integer, and print to stdout.

"""

import sys

t = sorted(map(int, sys.stdin.read().split()))

d = [t[i] - t[i-1] for i in range(1, len(t))]

afters = []
for i, g in enumerate(d):
    if g == 4 and i+1 < len(d):
        afters.append(d[i+1])

print(sum(afters) // len(afters) if afters else -1)
