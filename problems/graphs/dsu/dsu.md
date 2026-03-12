# disjoint set union / union-find
tracks a partition of elements into non-overlapping sets with near-constant-time merges and queries.

## in a nutshell
supports two operations: 
a) **find(a)** -> returns the fixed root of a's set
b) **union(a, b)** -> merges the two sets
with **path compression** and **union by rank/size**, both operations run in amortized **α(n)** time (inverse Ackermann, effectively constant for practical n).

## core ops
1. initialize every element as its own parent (a singleton set).
2. find(x): follow parents until a root; compress the path on the way back.
3. union(a, b): find roots ra, rb; if different, attach the smaller-rank tree under the larger.
4. optional: same(a, b) → whether two elements are in the same set.

## complexity analysis
- time (amortized): **find/union ~ O(α(n))** = O(E * logE) = O(E * logV); **same** is just two finds.
- space: **O(n)** for parents and ranks/sizes.
