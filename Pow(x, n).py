class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        return x**n
        
==========================================================================================
    def pow(self, x, m):
        negetive = False
        if m==0:
          return 1
        if m==1:
          return x
        if m<0:
          n = -m
          negetive = True
        else:
          n = m
        if n%2==0:
          if not negetive:
            return self.pow(x,n/2)**2
          else:
            return 1.0/self.pow(x,n/2)**2
        else:
          if not negetive:
            return x*self.pow(x,n/2)**2
          else:
            return 1.0/(x*self.pow(x,n/2)**2)
