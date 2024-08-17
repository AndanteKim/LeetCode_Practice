class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m, n = len(points), len(points[0])
        prev_r = points[0]
        
        for r in range(1, m):
            left_max, right_max = [0] * n, [0] * n
            curr_r = [0] * n
            
            # Calculate left-to-right maximum
            left_max[0] = prev_r[0]
            for c in range(1, n):
                left_max[c] = max(left_max[c - 1] - 1, prev_r[c])
                
            # Calculate right-to-left maximum
            right_max[-1] = prev_r[-1]
            for c in range(n - 2, -1, -1):
                right_max[c] = max(right_max[c + 1] - 1, prev_r[c])
                
            # Calculate the current row's maximum points
            for c in range(n):
                curr_r[c] = points[r][c] + max(left_max[c], right_max[c])
                
            # Update previous_row for the next iteration
            prev_r = curr_r
            
        # Find the maximum value in the last processed row
        return max(prev_r)