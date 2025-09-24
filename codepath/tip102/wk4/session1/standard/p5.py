def search_nft_by_tag(nft_collections, tag):
    r = []
    for c in nft_collections:
        for n in c:
            for t in n["tags"]:
                if t == tag:
                    r.append(n["name"])
    return r