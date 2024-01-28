class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n = len(matrix), len(matrix[0])
        
        # compute 2D prefix sum
        ps = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1]
                
        count = 0
        # Reduce 2D problem to 1D one
        # by fixing two rows r1 and r2 and
        # computing 1D prefix sum for all matrices using [r1..r2] rows
        for r1 in range(1, m + 1):
            for r2 in range(r1, m + 1):
                h = defaultdict(int)
                h[0] = 1
                
                for col in range(1, n + 1):
                    # current 1D prefix sum
                    curr_sum = ps[r2][col] - ps[r1 - 1][col]
                    
                    # add subarrays which sum up to (curr_sum - target)
                    count += h[curr_sum - target]
                    
                    # save current prefix sum
                    h[curr_sum] += 1
        
        return count