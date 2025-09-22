def next_greater_event(a, b):
    d, s = {}, []
    for x in b:
        while s and s[-1] < x: d[s.pop()] = x
        s.append(x)
    return [d.get(x, -1) for x in a]

print(next_greater_event([4, 1, 2], [1, 3, 4, 2]))
print(next_greater_event([2, 4], [1, 2, 3, 4]))