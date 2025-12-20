class SongNode:
    def __init__(self, song, artist, next=None):
        self.song = song
        self.artist = artist
        self.next = next

def print_linked_list(node):
    current = node
    while current:
        print((current.song, current.artist), end=" -> " if current.next else "")
        current = current.next
    print()

def get_artist_frequency(playlist):
    # Time complexity = O(n), where n = # of nodes in list
    f = {}
    while playlist:
        f[playlist.artist] = f.get(playlist.artist, 0) + 1
        playlist = playlist.next
