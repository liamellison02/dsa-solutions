def find_task_pair(tt, at):
    t = set()
    for d in tt:
        if at - d in t: return True
        else: t.add(d)
    return False