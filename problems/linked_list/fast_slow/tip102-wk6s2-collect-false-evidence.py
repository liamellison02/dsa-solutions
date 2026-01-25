class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def collect_false_evidence(evidence):
    # Time complexity = O(n/2 + m) = O(n), where n = # of nodes in list and m = length of loop
    if not (evidence or evidence.next):
        return evidence
    
    t, h = evidence, evidence.next
    while h and h.next:
        if t == h:
            l = [h.value]
            h = h.next
            while h and not h == t:
                l.append(h.value)
                h = h.next
            return l
        t = t.next
        h = h.next.next
    
    return 0