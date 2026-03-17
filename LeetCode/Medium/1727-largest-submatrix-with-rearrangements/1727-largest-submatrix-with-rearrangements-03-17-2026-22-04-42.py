class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] and i > 0:
                    matrix[i][j] += matrix[i - 1][j]
            
            curr_row = sorted(matrix[i], reverse = True)
            for k in range(n):
                ans = max(ans, curr_row[k] * (k + 1))

        return ans