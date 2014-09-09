class Solution:
    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
      
        INVALID = 0
        SPACE = 1
        SIGN  = 2
        DIGIT = 3
        DOT = 4
        EXPONENT = 5
        NUM_INPUTS = 6
        
        
        transitionTable = [
            [-1,  0,  3,  1,  2, -1],     # next states for state 0
            [-1,  8, -1,  1,  4,  5],     # next states for state 1
            [-1, -1, -1,  4, -1, -1],     # next states for state 2
            [-1, -1, -1,  1,  2, -1],     # next states for state 3
            [-1,  8, -1,  4, -1,  5],     # next states for state 4
            [-1, -1,  6,  7, -1, -1],     # next states for state 5
            [-1, -1, -1,  7, -1, -1],     # next states for state 6
            [-1,  8, -1,  7, -1, -1],     # next states for state 7
            [-1,  8, -1, -1, -1, -1]      # next states for state 8
            ]
        
        state = 0
        i = 0
        while i < len(s) :
            #*s = s[i]
            inputType = INVALID
            if (s[i]==' '):
                inputType = SPACE
            elif (s[i] == '+' or s[i] == '-'):
                inputType = SIGN
            elif (s[i] in "0123456789"):
                inputType = DIGIT
            elif (s[i] == '.'):
                inputType = DOT
            elif (s[i] == 'e' or s[i] == 'E'):
                inputType = EXPONENT
            
            state = transitionTable[state][inputType]
            
            if (state == -1):
                return False
            else:
                i+=1
        
        
        return state == 1 or state == 4 or state == 7 or state == 8
    
