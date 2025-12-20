# Standard Problem Set V1, Problem 1
def lineup(artists, set_times):
    ret = {}
    for a,st in zip(artists, set_times):
        ret[a]=st
    return ret
