class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        ans, rows, cols = 0, [0] * m, [0] * n

        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    rows[i] += 1
                    cols[j] += 1
        
        for i in range(m):
            for j in range(n):
                if mat[i][j] and rows[i] == 1 and cols[j] == 1:
                    ans += 1   

        return ans