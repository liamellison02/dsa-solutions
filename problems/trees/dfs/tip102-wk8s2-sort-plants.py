class TreeNode:
    def __init__(self, key, value, left=None, right=None):
        self.key = key
        self.val = value
        self.left = left
        self.right = right

def sort_plants(collection):
    if not collection: return []
    return sort_plants(collection.left) + [(collection.key, collection.val)] + sort_plants(collection.right)
