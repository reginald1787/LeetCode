# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def cmp(self,left,right):
        return left.start-right.start
        
    def merge(self,A):
        n = len(A)
        if n<=1:
            return A
        A.sort(cmp=self.cmp)
        i = 0
        j =i+1
        while j<n:
            if A[j].start<=A[i].end:
                A[i].end = max(A[i].end,A[j].end)
            else:
                i+=1
                A[i] = A[j]
            j+=1
        i+=1
        return A[:i]
     
        

        
        
