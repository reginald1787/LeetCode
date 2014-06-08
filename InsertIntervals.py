# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def merge(self,A):
        n = len(A)
        if n<=1:
            return A
        #A.sort(cmp=self.cmp)
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
        
    def insert(self, A, new):
        n = len(A)
        i=0
        if n<1:
            return [new]
        while i<n and A[i].start<new.start:
            i+=1
        A.insert(i,new)
        return self.merge(A)
        
