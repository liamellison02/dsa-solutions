def clean_post(post):
    if len(post) < 2:
        return post
    
    ret = []
    a, b = 0, 1

    while b < len(post):
        if ret and abs(ord(post[a])-ord(ret[-1])) == 32:
            ret.pop()
            a += 1
            b += 1
            continue

        if abs(ord(post[a])-ord(post[b])) == 32:
            a = b+1
            b = a+1
            continue

        ret.append(post[a])
        a += 1
        b += 1
    
    if b == len(post) and a == b-1:
        if ret and abs(ord(post[a])-ord(ret[-1])) == 32:
            ret.pop()
        else:
            ret.append(post[a])
    
    return ''.join(ret)
