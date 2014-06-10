# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param inorder, a list of integers
    # @param postorder, a list of integers
    # @return a tree node
    def totree(self,inor,post,s1,e1,e2):
        if s1>e1:
            return None
        res = TreeNode(post[e2])
        mid = 0
        i = s1
        while i<=e1:
            if inor[i]==res.val:
                mid = i
                break
            i+=1
        res.right = self.totree(inor,post,mid+1,e1,e2-1)
        res.left = self.totree(inor,post,s1,mid-1, e2-1-e1+mid)
        return res
        
    def buildTree(self, inorder, postorder):
        if postorder==[]:
            return None
        return self.totree(inorder,postorder,0,len(inorder)-1,len(postorder)-1)
    
        
        
