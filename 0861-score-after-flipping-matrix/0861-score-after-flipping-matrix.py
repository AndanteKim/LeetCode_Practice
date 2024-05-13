class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        # Set first column
        for i in range(m):
            if grid[i][0] == 0:
                # Flip row
                for j in range(n):
                    grid[i][j] ^= 1 #- grid[i][j] # Bitwise XOR for flip
                    
        # Optimize columns except first column
        for j in range(1, n):
            count_zero = 0
            # Count zeros
            for i in range(m):
                if grid[i][j] == 0:
                    count_zero += 1
            
            # Flip the column if more zeros for better score
            if count_zero > m - count_zero:
                for i in range(m):
                    grid[i][j] ^= 1 # Bitwise XOR for flip
                    
        # Calculate the final score considering bit positions
        ans = 0
        for i in range(m):
            for j in range(n):
                # Left shift bit by place value of column to find column contribution
                column_score = grid[i][j] << (n - j - 1)
                # Add contributio nto score
                ans += column_score
        
        # Return the final result
        return ans
        
        