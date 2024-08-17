class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points[0])
        curr_row, prev_row = [0] * n, [0] * n
        
        for row in points:
            # Running_max holds the maximum value generated in the previous iteration of each loop
            running_max = 0
            
            # Left to right pass
            for col in range(n):
                running_max = max(running_max - 1, prev_row[col])
                curr_row[col] = running_max
                
            running_max = 0
            # Right to left pass
            for col in range(n - 1, -1, -1):
                running_max = max(running_max - 1, prev_row[col])
                curr_row[col] = max(curr_row[col], running_max) + row[col]
                
            # Update previous_row for next iteration
            prev_row = curr_row[:]
            
        # Find the maximum points in the last row
        return max(prev_row)
        