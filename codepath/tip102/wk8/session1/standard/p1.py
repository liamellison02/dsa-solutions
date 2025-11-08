class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.left = left
        self.right = right

root = TreeNode("Trunk")
root.left = TreeNode("Mcintosh", TreeNode("Fuji"), TreeNode("Opal"))
root.right = TreeNode("Granny Smith", TreeNode("Crab"), TreeNode("Gala"))