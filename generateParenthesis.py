class Solution:
    # @param an integer
    # @return a list of string
    def gen(self,n):
    	if n<1:
    		return []
    	if n==1:
    		return ['()']
    	res = []
    	for i in range(1,n):
    		if i==1:
    			front = ['()']
    		else:
    			front = ['('+s+')' for s in self.gen(i-1)]
    		back = self.gen(n-i)
    		if back:
    			front =[w1+w2 for w1 in front for w2 in back]
    		res += front
    
    	res += ['('+s+')' for s in self.gen(n-1)]
    
    	return res
    	
    def generateParenthesis(self,n):
        return self.gen(n)
