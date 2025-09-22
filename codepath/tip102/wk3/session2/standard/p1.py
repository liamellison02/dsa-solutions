def manage_stage_changes(changes):
    s1 = []
    s2 = []
    for op in changes:
        if op == "Cancel": s2.append(s1.pop())
        elif op == "Reschedule": s1.append(s2.pop())
        else: s1.append(op[-1])
    return s1