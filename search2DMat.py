class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def bs(self,A,t):
    	n = len(A)
    	if n<1:
    		return False
    	mid = n/2
    	if A[mid]==t:
    		return True
    	if A[mid]<t:
    		return self.bs(A[mid+1:],t)
    	else:
    		return self.bs(A[:mid],t)
    		
    def searchMatrix(self, A, t):
    	m = len(A)
    	if m<1:
    		return False
    	#n = len(A[0])
    
    	mid = m/2
    	
    	if self.bs(A[mid],t):
    		return True
    
    	if t<A[mid][0]:
    		return self.searchMatrix(A[:mid],t)
    	if t>A[mid][len(A[mid])-1]:
    		return self.searchMatrix(A[mid+1:],t)
    	else:
    		return False
