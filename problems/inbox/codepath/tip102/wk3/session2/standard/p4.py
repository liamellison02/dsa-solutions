def booth_navigation(clues):
    s = []
    for c in clues:
        if c == "back":
            if s: s.pop()
        else:
            s.append(c)
    return s