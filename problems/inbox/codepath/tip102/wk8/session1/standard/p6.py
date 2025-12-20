class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

def survey_tree(root):
    if not root: return []
    return survey_tree(root.left) + survey_tree(root.right) + [root.val]
