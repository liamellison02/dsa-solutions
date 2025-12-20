class SongNode:
    def __init__(self, song, artist, next=None):
        self.song = song
        self.artist = artist
        self.next = next

def on_repeat(playlist_head):
    # Time complexity = O(n/2) = O(n), where n = # of nodes in list
    if not (playlist_head or playlist_head.next):
        return playlist_head
    
    t, h = playlist_head, playlist_head.next
    while h and h.next:
        if t == h:
            return True
        t = t.next
        h = h.next.next
    
    return False
