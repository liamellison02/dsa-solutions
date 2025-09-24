def identify_popular_creators(nft_collection):
    s,r = set(), []
    for n in nft_collection:
        c = n["creator"]
        if c in s:
            r.append(c)
        else:
            s.add(c)
    return r