def find_smallest_gap(s):
    def hm(t):
        return (t//100, t%100)
    l, r = (0,0), float('inf')
    for i in range(1, len(s)):
        h,m = hm(s[i][0])
        r = min((h-l[0])*60 + m-l[1], r)
        l = hm(s[i][1])
    return int(r)