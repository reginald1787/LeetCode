class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        row = set([])
        col = set([])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j]==0:
                    if i not in row:
                        row.add(i)
                    if j not in col:
                        col.add(j)
        for i in row:
            for j in range(len(matrix[0])):
                matrix[i][j]=0
        for j in col:
            for i in range(len(matrix)):
                matrix[i][j] = 0
                
        
                        
        
        
