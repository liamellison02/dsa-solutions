def is_symmetrical_title(title):
    title = title.replace(" ", "").lower()
    l, r = 0, len(title)-1
    while l <= r:
        if not title[l].isalnum():
            l += 1
            continue
        if not title[r].isalnum():
            r -= 1
            continue
        if not title[l] == title[r]:
            return False
        l += 1
        r -= 1
    return True
