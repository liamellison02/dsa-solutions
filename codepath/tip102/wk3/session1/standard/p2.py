def reverse_comments_queue(comments):
    ret = []
    for i in range(len(comments)-1, -1, -1):
        ret.append(comments[i])
    return ret