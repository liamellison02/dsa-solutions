def pick_plant(inv, budget):
    curr, best = inv, None
    while curr:
        if curr.val >= budget:
            curr = curr.left
        else:
            best = curr
            curr = curr.right
    return best
        