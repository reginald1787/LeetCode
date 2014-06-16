class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of lists of integers
    def rotate(self,mat):
    	n = len(mat)
    	if n<1:
    		return []
    	if n==1:
    		return mat
    	
    	if n%2==1:
    		length = 1
    		i = n/2
    		j = n/2
    	else:
    		length = 2
    		i = n/2-1
    		j = n/2-1
    	while  length<=n:
    		pos = 0
    		while pos<length-1:
    			tmp = mat[i][j+pos]
    			mat[i][j+pos] = mat[i+length-1-pos][j]
    			mat[i+length-1-pos][j] = mat[i+length-1][j+length-1-pos]
    			mat[i+length-1][j+length-1-pos] = mat[i+pos][j+length-1]
    			mat[i+pos][j+length-1]=tmp
    			pos+=1
    		length+=2
    		i-=1
    		j-=1
    
    	return mat
