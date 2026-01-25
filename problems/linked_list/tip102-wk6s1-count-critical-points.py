class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def count_critical_points(song_audio):
    # Time complexity = O(n), where n = # of nodes in list
    if not (song_audio or song_audio.next or song_audio.next.next):
        return 0

    prev, curr, pts = song_audio, song_audio.next, 0
    while curr.next:
        if prev.value > curr.value < curr.next.value:
            pts += 1
        elif prev.value < curr.value > curr.next.value:
            pts += 1
        prev = prev.next
        curr = curr.next
    
    return pts
