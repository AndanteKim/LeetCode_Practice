class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def is_magic_square(row: int, col: int) -> bool:
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
            dia1 = (
                grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]
            )

            dia2 = (
                grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][ col]
            )

            if dia1 != dia2:
                return False

            # Check if all row sums are the same as the diagonal sums
            for i in range(row, row + 3):
                row_sum = 0
                for j in range(col, col + 3):
                    row_sum += grid[i][j]
                if row_sum != dia1 or row_sum != dia2:
                    return False
                
            # Check if all col sums are the same as the diagonal sums
            for j in range(col, col + 3):
                col_sum = 0
                for i in range(row, row + 3):
                    col_sum += grid[i][j]
                
                if col_sum != dia1 or col_sum != dia2:
                    return False
            
            return True

        # Base case
        if len(grid) < 3 or len(grid[0]) < 3:
            return 0
        
        ans, m, n = 0, len(grid), len(grid[0])

        for row in range(m - 2):
            for col in range(n - 2):
                if is_magic_square(row, col):
                    ans += 1

        return ans