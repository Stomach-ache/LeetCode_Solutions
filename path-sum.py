# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a boolean
    def hasPathSum(self, root, sum):
        if root is None:
            return False
        if root.left is None and root.right is None:
            return True if root.val == sum else False
        if root.left != None and self.hasPathSum(root.left, sum-(root.val)):
            return True
        if root.right != None and self.hasPathSum(root.right, sum-(root.val)):
            return True
        return False
