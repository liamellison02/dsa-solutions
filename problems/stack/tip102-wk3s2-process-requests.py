from collections import deque, defaultdict
def process_performance_requests(r):
    q=deque(r); b=defaultdict(deque)
    while q:
        p,n=q.popleft(); b[p].append(n)
    a=[]
    for p in sorted(b.keys(), reverse=True):
        d=b[p]
        while d:
            a.append(d.popleft())
    return a

def how_i_woulda_dunnit_if_i_wasnt_forced_to_use_a_q_lol(r):
    return [n for p, n in sorted(r, key=lambda x: -x[0])]  # lmao