def is_valid_post_format(posts):
    valid = {
        ")": "(", 
        "}":"{", 
        "]":"["
    }
    open = []
    for t in posts:
        if t in valid.values():
            open.append(t)
        else:
            if not open or valid[t] != open[-1]:
                return False
            open.pop()
    
    return True
