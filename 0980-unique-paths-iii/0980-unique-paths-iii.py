class Solution:
    def backtrack(self, row: int, col: int, remain: int, grid: List[List[int]]) -> None:
        if grid[row][col] == 2 and remain == 1:
            self.ans += 1
            return
        
        if grid[row][col] == 2:
            return
        
        temp = grid[row][col]
        grid[row][col] = -4
        remain -= 1
        
        for r, c in (row + 1, col), (row - 1, col), (row, col + 1), (row, col - 1):
            if r < 0 or c < 0 or r >= self.m or c >= self.n:
                continue
            if grid[r][c] < 0:
                continue
            
            self.backtrack(r, c, remain, grid)
            
        grid[row][col] = temp
    
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        self.m, self.n = len(grid), len(grid[0])
        non_obstacles, start_row, start_col = 0, 0, 0
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] >= 0:
                    non_obstacles += 1
                if grid[i][j] == 1:
                    start_row, start_col = i, j
        
        self.ans = 0
        self.backtrack(start_row, start_col, non_obstacles, grid)
        return self.ans