class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        ans = 0
        min_abs_val, neg_cnt = float('inf'), 0

        for row in matrix:
            for val in row:
                ans += abs(val)
                if val < 0:
                    neg_cnt += 1
                min_abs_val = min(min_abs_val, abs(val))
        
        # Adjust if the count of negative numbers is odd
        if neg_cnt % 2:
            ans -= 2 * min_abs_val

        return ans
