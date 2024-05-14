class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def backtrack(r: int, c: int) -> int:
            # Base case: This is not in the matrix or has no gold
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == 0:
                return 0
            
            max_gold = 0
            
            # Mark the cell as visited and save the value
            original_val = grid[r][c]
            grid[r][c] = 0
            
            # Backtrack in each of the four directions
            for i in range(4):
                max_gold = max(max_gold, backtrack(r + dirs[i], c + dirs[i + 1]))
            
            # Set the cell back to its original value
            grid[r][c] = original_val
            return max_gold + original_val
        
        m, n, ans = len(grid), len(grid[0]), 0
        dirs = (0, -1, 0, 1, 0)
        
        # Search for the path with the maximum gold starting from each cell
        for i in range(m):
            for j in range(n):
                ans = max(ans, backtrack(i, j))
            
        return ans