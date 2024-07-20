class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        matrix = [[0] * n for _ in range(m)]
        curr_r_sum, curr_c_sum = [0] * m, [0] * n
        
        for i in range(m):
            for j in range(n):
                matrix[i][j] = min(rowSum[i] - curr_r_sum[i], colSum[j] - curr_c_sum[j])
                
                curr_r_sum[i] += matrix[i][j]
                curr_c_sum[j] += matrix[i][j]
        
        return matrix