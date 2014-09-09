# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def mini(self,root):
        pre = root
        p = root.left
        while p:
            pre = p
            p = p.left
        return pre.val
    def maxi(self,root):
        pre = root
        p = pre.right
        while p:
            pre = p
            p = p.right
        return pre.val
            
    def isValidBST(self, root):
        if not root:
            return True
        if root.left==None and root.right==None:
            return True
        if self.isValidBST(root.left) and self.isValidBST(root.right):
            if root.left and self.maxi(root.left)>=root.val:
                return False
            if root.right and self.mini(root.right)<=root.val:
                return False
            return True
        return False
        
