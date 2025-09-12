# Standard Problem Set V1, Problem 2
from collections import Counter
def count_endangered_species(endangered_species, observed_species):
    freq = Counter(observed_species)
    endangered = set(endangered_species)
    count = 0
    for s in endangered:
        count += freq[s]
    return count
