def extract_nft_names(c):
    l = []
    for n in c:
        l.append(n["name"])
    return l