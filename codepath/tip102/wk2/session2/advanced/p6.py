# Advanced Problem Set V1, Problem 6
def count_divisible_collections(collection_sizes, k):
    cnt, n = 0, len(collection_sizes)
    for i in range(n):
        curr = 0
        for j in range(i, n):
            curr += collection_sizes[j]
            if curr % k == 0:
                cnt+=1
    return cnt
