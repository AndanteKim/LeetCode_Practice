class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        ans, candidates = [], []
        
        for i in range(m):
            min_row, curr = float('inf'), (0, 0)
            for j in range(n):
                if min_row > matrix[i][j]:
                    curr = (i, j)
                    min_row = matrix[i][j]
            candidates.append(curr)
        
        for i, j in candidates:
            max_col, curr = float('-inf'), (0, 0)
            for k in range(m):
                if max_col < matrix[k][j]:
                    curr = (k, j)
                    max_col = matrix[k][j]
            if matrix[i][j] == max_col:
                ans.append(matrix[i][j])
        
        return ans