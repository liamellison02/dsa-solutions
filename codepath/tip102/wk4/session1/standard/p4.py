def average_nft_value(nft_collection):
    c,s = 0,0
    for n in nft_collection:
        c+=1
        s+=n["value"]
    return 0 if not nft_collection else s/c