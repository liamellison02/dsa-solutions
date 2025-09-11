# Advanced Problem Set V1, Problem 4
from collections import Counter

def can_make_balanced(code):
    counts = Counter(code)
    freq = Counter(counts.values())
    
    if len(freq) == 1:
        return True if len(code) == 1 else False

    if len(freq) == 2:
        (a, ca), (b, cb) = sorted(freq)
        return True if (a == 1 and ca == 1) or (b == a+1 and cb == 1) else False

    return False
