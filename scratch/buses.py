"""

Q1:
Read in a sequence of integers from stdin. Calculate their sum.


Q2:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You arrive at the bus stop, you read in the times and unhappily discover that you left your watch at home.
You know that you are still in the 0 to 1000 interval, but you aren't sure of the exact time.

How long do you expect to wait until the next bus arrives?
Round down to the nearest integer, and print your answer to stdout.


Q3:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You left your watch at home.
You've just observed 2 buses arriving 4 units of time apart, what is the expected time until the next bus arrives?

Round your answer down to the lowest integer, and print to stdout.


Q4:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You have a watch, but it is not set properly. 
You can tell that you've been at the bus stop for 3 units of time, but still have not seen any buses. 
How much longer do you expect to wait until one arrives?

Round your answer down to the nearest integer, and print to stdout.


Q5:
You have a bus schedule that covers the time interval [0, 1000]. 
You can assume that all buses arrive on schedule and that a bus will always be schedule to arrive at time 1000. 
You can read these times from stdin.

You have a watch, but it is not set correctly. 
How many bus arrivals do you need to witness to determine the current time?

Print your answer to stdout.

"""

import sys

t = sorted(map(int, sys.stdin.read().split()))

d = [t[i] - t[i-1] for i in range(1, len(t))]

afters = []
for i, g in enumerate(d):
    if g == 4 and i+1 < len(d):
        afters.append(d[i+1])

print(sum(afters) // len(afters) if afters else -1)
