class Solution:
    # @return a boolean
    def isleft(self,c):
        if c=='(' or c=='{' or c=='[':
            return True
        return False
        
    def isright(self,c):
        if c==')' or c=='}' or c==']':
            return True
        return False
        
    def match(self,a,b):
        if a=='(' and b==')':
            return True
        if a=='{' and b=='}':
            return True
        if a=='[' and b==']':
            return True
        return False
        
    def isValid(self, s):
        if s=='':
            return True
        stack = []
        for c in s:
            if self.isleft(c):
                stack.append(c)
            elif self.isright(c):
                if stack==[]:
                    return False
                l  = stack.pop()
                if not self.match(l,c):
                    return False
            else:
                return False
        if stack==[]:
            return True
        return False
