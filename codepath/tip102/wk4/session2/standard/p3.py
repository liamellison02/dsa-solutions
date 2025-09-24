def calculate_expenses(xs):
    t = {}
    for k, v in xs: t[k] = t.get(k, 0) + v
    return t, (max(t, key=t.get) if t else None)