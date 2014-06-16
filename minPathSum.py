class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, A):
    	m = len(A)
    	if m<1:
    		return 0
    	n = len(A[0])
    
    	if m==1:
    		return sum(A[0])
    	if n==1:
    		temp = 0
    		for i in range(m):
    			temp+=A[i][0]
    		return temp
    
    	matsum = A
    	for i in range(m-2,-1,-1):
    		matsum[i][n-1] += matsum[i+1][n-1]
    	for j in range(n-2,-1,-1):
    		matsum[m-1][j] += matsum[m-1][j+1]
    
    	for i in range(m-2,-1,-1):
    		for j in range(n-2,-1,-1):
    			matsum[i][j] = min(matsum[i][j]+matsum[i+1][j],matsum[i][j]+matsum[i][j+1])
    
    
    	return matsum[0][0]
