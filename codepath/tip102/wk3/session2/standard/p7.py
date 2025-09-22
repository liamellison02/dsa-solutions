def sort_performances_by_type(p):
    return [x for x in p if x % 2 == 0] + [x for x in p if x % 2 == 1]