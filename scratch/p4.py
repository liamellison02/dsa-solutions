"""

Q4:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You have a watch, but it is not set properly. 
You can tell that you've been at the bus stop for 3 units of time, but still have not seen any buses. 
How much longer do you expect to wait until one arrives?

Round your answer down to the nearest integer, and print to stdout.

"""

import sys

t = sorted(map(int, sys.stdin.read().strip()))

d = [t[i] - t[i-1] for i in range(1, len(t))]

rem = [g for g in d if g > 3]

# summation of p(g_i)*(g_i/2)
# p(g_i) = g_i / sum(g)

ss, denom = 0, sum(rem) * 2
for g in rem:
    ss += g*g

print(ss // denom)
