class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        row_count, col_count = [0] * m, [0] * n
        
        for row in range(m):
            for col in range(n):
                if mat[row][col] == 1:
                    row_count[row] += 1
                    col_count[col] += 1
        
        ans = 0
        for row in range(m):
            for col in range(n):
                if mat[row][col] == 1:
                    if row_count[row] == 1 and col_count[col] == 1:
                        ans += 1
        
        return ans
        
        