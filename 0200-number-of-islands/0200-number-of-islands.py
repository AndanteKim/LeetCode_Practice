class Solution:
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    def valid(self, row: int, col: int) -> bool:
        return 0 <= row < self.m and 0 <= col < self.n and self.grid[row][col] == '1'
    
    def dfs(self, row: int, col: int) -> None:
        for dx, dy in self.directions:
            next_row, next_col = row + dy, col + dx
            if self.valid(next_row, next_col) and (next_row, next_col) not in self.seen:
                self.seen.add((next_row, next_col))
                self.dfs(next_row, next_col)
        
    
    def numIslands(self, grid: List[List[str]]) -> int:
        self.m, self.n, self.grid = len(grid), len(grid[0]), grid
        self.seen, ans = set(), 0
        
        for row in range(self.m):
            for col in range(self.n):
                if self.grid[row][col] == '1' and (row, col) not in self.seen:
                    ans += 1
                    self.seen.add((row, col))
                    self.dfs(row, col)
                    
        return ans
            