class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_sum, min_val = 0, float('inf')
        neg_cnt = 0
        
        for row in matrix:
            for val in row:
                total_sum += abs(val)
                min_val = min(min_val, abs(val))
                neg_cnt += (val >> 31) & 1;
                
            
        return total_sum - (min_val << 1) if neg_cnt & 1 else total_sum