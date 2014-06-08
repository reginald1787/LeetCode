class Solution:
    # @return a tuple, (index1, index2)
    def find(self,A,start,end,key):
        if start>end:
            return -1
        mid = (start+end)/2
        if A[mid] == key:
            return mid
        if A[mid]>key:
            return self.find(A,start,mid-1,key)
        else:
            return self.find(A,mid+1,end,key)
        
    def twoSum(self, num, target):
        A = sorted(num)
        index = sorted(range(len(num)), key=lambda k: num[k])
        n = len(A)
        for i in range(n):
            if self.find(A,i+1,n-1,target-A[i])>-1:
                index1 = min(index[i]+1,index[self.find(A,i+1,n-1,target-A[i])]+1)
                index2 = max(index[i]+1,index[self.find(A,i+1,n-1,target-A[i])]+1)
                return (index1,index2)
