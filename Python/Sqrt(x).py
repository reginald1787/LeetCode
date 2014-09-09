class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        if x<2:
            return x
        y = x/2+1
        while y**2>x:
            y = (y+x/y)/2
        return y
        
