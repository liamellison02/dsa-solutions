class SongNode:
    def __init__(self, song, artist, next=None):
        self.song = song
        self.artist = artist
        self.next = next

def loop_length(playlist_head):
    # Time complexity = O(n/2 + m) = O(n), where n = # of nodes in list and m = length of loop
    if not (playlist_head or playlist_head.next):
        return playlist_head
    
    t, h = playlist_head, playlist_head.next
    while h and h.next:
        if t == h:
            l = 1
            h = h.next
            while h and not h == t:
                h = h.next
                l+=1
            return l
        t = t.next
        h = h.next.next
    
    return 0
