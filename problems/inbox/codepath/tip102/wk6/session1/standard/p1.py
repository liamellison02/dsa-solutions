class SongNode:    
    def __init__(self, song, next=None):
        self.song = song
        self.next = next

def print_linked_list(node):
    current = node
    while current:
        print(current.song, end=" -> " if current.next else "")
        current = current.next
    print()

head = SongNode("Uptown Funk")
head.next = SongNode("Party Rock Anthem")
head.next.next = SongNode("Bad Romance")