class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        self.m, self.n = len(grid), len(grid[0])
        
        # Base case
        if self.m < 3 or self.n < 3:
            return 0
        
        ans = 0
        for i in range(self.m - 2):
            for j in range(self.n - 2):
                if self._is_magic_square(grid, i, j):
                    ans += 1
                    
        return ans
    
    def _is_magic_square(self, grid: List[List[int]], row: int, col: int) -> bool:
        seen = [False] * 10
        
        for i in range(3):
            for j in range(3):
                num = grid[row + i][col + j]
                if num < 1 or num > 9:
                    return False
                
                if seen[num]:
                    return False
                
                seen[num] = True
                
        # Check if diagonal sums are the same
        dia, anti_dia = 0, 0
        for k in range(3):
            dia += grid[row + k][col + k]
            anti_dia += grid[row + 2 - k][col + k]
        if dia != anti_dia:
            return False
        
        # Check if all row sums are the same as the diagonal sums
        row_sum = [0] * 3
        for i in range(3):
            for j in range(3):
                row_sum[i] += grid[row + i][col + j]
        
        for i in range(3):
            if row_sum[i] != dia:
                return False
            
        # Check if all column sums are the same as the diagonal sums
        col_sum = [0] * 3
        for i in range(3):
            for j in range(3):
                col_sum[i] += grid[row + j][col + i]
        
        for i in range(3):
            if col_sum[i] != dia:
                return False
            
        return True