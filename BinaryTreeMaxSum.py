# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def __init__(self):
        self.maxsum = -9999
        
    def pathsum(self,root):
        if not root:
            return 0
        l = self.pathsum(root.left)
        r = self.pathsum(root.right)
        currsum = root.val
        if l>0:
            currsum+=l
        if r>0:
            currsum+=r
        self.maxsum = max(self.maxsum,currsum)
        if max(l,r)>0:
            return max(l,r) + root.val
        else:
            return root.val
            
    def maxPathSum(self, root):
        self.pathsum(root)
        return self.maxsum
        
