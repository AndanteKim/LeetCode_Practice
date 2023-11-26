class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n, ans = len(matrix), len(matrix[0]), 0
        prev_row = [0] * n
        
        for row in range(m):
            curr_row = matrix[row][:]
            for col in range(n):
                if curr_row[col]:
                    curr_row[col] += prev_row[col]
                
            sorted_row = sorted(curr_row, reverse = True)
            for i in range(n):
                ans = max(ans, sorted_row[i] * (i + 1))
            prev_row = curr_row
        
        return ans