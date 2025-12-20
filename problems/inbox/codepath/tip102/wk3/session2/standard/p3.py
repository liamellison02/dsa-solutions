def collect_festival_points(points):
    s = []
    for x in points: s.append(x)
    t = 0
    while s: t += s.pop()
    return t