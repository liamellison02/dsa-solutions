# Standard Problem Set V1, Problem 6
from collections import Counter
def max_species_copies(raised_species, target_species):
    freq, cnt = Counter(raised_species), float('inf')
    for s in target_species:
        cnt = min(cnt, freq[s])
    return cnt
