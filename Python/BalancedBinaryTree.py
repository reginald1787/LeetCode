# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def validBalance(self,root, depth):
        if root == None:
            depth = 0
            return True
        leftdepth =0
        if not self.validBalance(root.left, leftdepth):
            return False
        rightdepth =0
        if not self.validBalance(root.right, rightdepth):
            return False
        depth = max(leftdepth,rightdepth)+1
        return (leftdepth == rightdepth) or (leftdepth == rightdepth + 1) or (leftdepth + 1 == rightdepth)
        
    def isBalanced(self, root):
        depth = 0
        return self.validBalance(root,depth)
