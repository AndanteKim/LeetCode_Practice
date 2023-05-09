class Solution:
    def compress_matrix(self, matrix: List[List[int]]) -> List[List[int]]:
        rows, cols = len(matrix), len(matrix[0])
        compressed_matrix = [[] for _ in range(rows)]
        for row in range(rows):
            for col in range(cols):
                if matrix[row][col]:
                    compressed_matrix[row].append([matrix[row][col], col])
        return compressed_matrix
    
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        m, k, n = len(mat1), len(mat1[0]), len(mat2[0])
        
        A, B = self.compress_matrix(mat1), self.compress_matrix(mat2)
        ans = [[0] * n for _ in range(m)]
        
        for mat1_row in range(m):
            for element1, mat1_col in A[mat1_row]:
                for element2, mat2_col in B[mat1_col]:
                    ans[mat1_row][mat2_col] += element1 * element2
        return ans