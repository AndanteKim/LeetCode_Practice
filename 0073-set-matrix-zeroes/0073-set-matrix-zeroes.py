class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n, flatten = len(matrix), len(matrix[0]), 0
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0 and flatten & (1 << (n * i + j)) == 0:
                    for col in range(n):
                        if matrix[i][col] != 0:
                            flatten |= (1 << (n * i + col))
                            matrix[i][col] = 0
                    
                    for row in range(m):
                        if matrix[row][j] != 0:
                            flatten |= (1 << (n * row + j))
                            matrix[row][j] = 0