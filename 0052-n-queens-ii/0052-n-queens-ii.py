class Solution:
    def totalNQueens(self, n: int) -> int:
        def backtrack(row: int, diagonals: int, anti_diagonals: int, cols: int) -> int:
            if row == n:
                return 1
            
            # bitmask solution more efficient than hashmap set
            solutions = 0
            for col in range(n):
                curr_diagonal = 1 << (row - col + n)
                curr_anti_diagonal = 1 << (row + col)
                curr_col = 1 << col
                
                if curr_col & cols or curr_diagonal & diagonals or curr_anti_diagonal & anti_diagonals:
                    continue
                
                cols ^= curr_col
                diagonals ^= curr_diagonal
                anti_diagonals ^= curr_anti_diagonal
                
                solutions += backtrack(row + 1, diagonals, anti_diagonals, cols)
                
                cols ^= curr_col
                diagonals ^= curr_diagonal
                anti_diagonals ^= curr_anti_diagonal
                
            return solutions
        
        return backtrack(0, 0, 0, 0)
            
            
            
            