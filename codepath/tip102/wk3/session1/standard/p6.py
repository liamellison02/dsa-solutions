from collections import deque
def edit_post(post):
    result = []
    q = deque()
    for c in post:
        if c != ' ':
            q.append(c)
        else:
            word = []
            while q:
                word.insert(0, q.popleft())
            result.extend(word)
            result.append(' ')
    word = []
    while q:
        word.insert(0, q.popleft())
    result.extend(word)
    return ''.join(result)
