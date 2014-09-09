# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        p1 = l1
        p2 = l2
        if p1==None:
            return p2
        if p2==None:
            return p1
        first = True
        if p1.val<p2.val:
            head = p1
        else:
            head = p2
            first = False
        p = head
        while p1.next and p2.next:
            if p1.next.val<p2.next.val:
                p.next = p1.next
                p = p.next
                p1 = p1.next
            else:
                p.next = p2.next
                p = p.next
                p2 = p2.next
        if first and p1.next==None:
            p1.next = p2.next
        elif not first and p2.next == None:
            p2.next = p1.next
        return head
