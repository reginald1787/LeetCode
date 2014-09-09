class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        if n<=2:
            return n
        a = 0
        b = 0
        c = 1
        for i in range(n):
            a = b
            b = c
            c = a + b
        
        return c
