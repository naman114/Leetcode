class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        
        for i in range(rows):
            for j in range(cols):
                if(i < j):
                    temp = matrix[i][j]
                    matrix[i][j] = matrix[j][i]
                    matrix[j][i] = temp
        
        for i in range(rows):
            for j in range(int(cols/2)):
                temp = matrix[i][j]
                matrix[i][j] = matrix[i][cols - j - 1]
                matrix[i][cols - j - 1] = temp