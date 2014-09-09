# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def __init__(self):
        self.head  = None
    def tobst(self,s,e):
        if s>e:
            return None
        l = self.tobst(s,s+(e-s)/2-1)
        p = TreeNode(self.head.val)
        self.head = self.head.next
        r = self.tobst(s+(e-s)/2+1,e)
        p.left = l
        p.right = r
        return p
        
        
    def sortedListToBST(self, head):
        n = 0
        p = head
        if not head:
            return
        while p:
            n+=1
            p = p.next
        self.head = head
        return self.tobst(1,n)
        
