class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_sum, min_abs_val = 0, float('inf')
        negative_cnt = 0
        
        for row in matrix:
            for val in row:
                total_sum += abs(val)
                if val < 0:
                    negative_cnt += 1
                min_abs_val = min(min_abs_val, abs(val))
        
        # Adjust if the count of negative numbers is odd.
        if negative_cnt % 2:
            total_sum -= 2 * min_abs_val
            
        return total_sum