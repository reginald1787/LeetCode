class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    
    def twoSum(self, A, target):
        #A = sorted(num)
        #index = sorted(range(len(num)), key=lambda k: num[k])
        i = 0
        j = len(A)-1
        res = []
        while i<j:
            sum = A[i]+A[j]
            if sum==target:
                res.append((A[i],A[j]))
                i+1
                j-=1
            elif sum<target:
                i+=1
            else:
                j-=1
        return res
                
        
    def threeSum(self, num):
        A = sorted(num)
        #index = sorted(range(len(num)), key=lambda k: num[k])
        results = []
        for i in range(len(A)):
            a = A[i]
            target = -a
            if self.twoSum(A[i+1:],target) == []:
                break
            B = self.twoSum(A[i+1:],target)
            for (b,c) in B: 
                if sorted([a,b,c]) not in results:
                    results.append(sorted([a,b,c]))
        return results
            
           
        
        
