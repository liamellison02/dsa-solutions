# Advanced Problem Set V1, Problem 1
from collections import Counter
def find_balanced_subsequence(art_pieces):
    cnt, n = Counter(art_pieces), 0
    for p,c in cnt.items():
        n = max(n, cnt[p-1]+cnt[p] if cnt[p-1] > 0 else 0, cnt[p]+cnt[p+1] if cnt[p+1] > 0 else 0)
    return n
