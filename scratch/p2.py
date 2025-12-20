"""

Q2:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You arrive at the bus stop, you read in the times and unhappily discover that you left your watch at home.
You know that you are still in the 0 to 1000 interval, but you aren't sure of the exact time.

How long do you expect to wait until the next bus arrives?
Round down to the nearest integer, and print your answer to stdout.

"""

import sys

t = sorted(map(int, sys.stdin.read().split()))

# summation of P(g)*(d/2)
# P(d) = d/1000

ss = 0
for i in range(1, len(t)):
    d = t[i] - t[i-1]
    ss += d*d

print(ss // 2000)
