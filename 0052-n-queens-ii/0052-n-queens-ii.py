class Solution:
    def backtrack(self, row: int, diagonals: int, anti_diagonals: int, cols: int) -> int:
        if row == self.n:
            return 1
            
        # bitmask solution more efficient than hashmap set
        solutions = 0
        for col in range(self.n):
            curr_diagonal = 1 << (row - col + self.n)
            curr_anti_diagonal = 1 << (row + col)
            curr_col = 1 << col
                
            if curr_col & cols or curr_diagonal & diagonals or curr_anti_diagonal & anti_diagonals:
                continue
                
            cols ^= curr_col
            diagonals ^= curr_diagonal
            anti_diagonals ^= curr_anti_diagonal
                
            solutions += self.backtrack(row + 1, diagonals, anti_diagonals, cols)
                
            cols ^= curr_col
            diagonals ^= curr_diagonal
            anti_diagonals ^= curr_anti_diagonal
                
        return solutions
    
    def totalNQueens(self, n: int) -> int:
        self.n = n
        return self.backtrack(0, 0, 0, 0)