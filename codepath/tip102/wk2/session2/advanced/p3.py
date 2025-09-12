# Advanced Problem Set V1, Problem 3
from collections import Counter
def organize_exhibition(collection):
    cnt = Counter(collection)
    ret = [[] for _ in range(max(cnt.values()))]
    for p,c in cnt.items():
        while c > 0:
            ret[c-1].append(p)
            c-=1
    return ret
