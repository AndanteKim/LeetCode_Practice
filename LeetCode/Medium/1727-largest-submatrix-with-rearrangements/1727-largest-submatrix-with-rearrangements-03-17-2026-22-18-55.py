class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        prev_row, ans = [0] * n, 0

        for i in range(m):
            curr_row = matrix[i][:]
            for j in range(n):
                if curr_row[j] != 0:
                    curr_row[j] += prev_row[j]
            
            sorted_row = sorted(curr_row, reverse = True)
            for k in range(n):
                ans = max(ans, (k + 1) * sorted_row[k])
            prev_row = curr_row
            
        return ans