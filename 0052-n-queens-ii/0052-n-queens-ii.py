class Solution:
    def backtrack(self, row: int, diagonals: Set[int], anti_diagonals: Set[int], cols: Set[int]) -> int:
        if row == self.n:
            return 1
        
        ans = 0
        for col in range(self.n):
            curr_diagonal = row - col
            curr_anti_diagonal = row + col
            
            if col in cols or curr_diagonal in diagonals or curr_anti_diagonal in anti_diagonals:
                continue
                
            cols.add(col)
            diagonals.add(curr_diagonal)
            anti_diagonals.add(curr_anti_diagonal)
            ans += self.backtrack(row + 1, diagonals, anti_diagonals, cols)
            cols.remove(col)
            diagonals.remove(curr_diagonal)
            anti_diagonals.remove(curr_anti_diagonal)
        
        return ans
    
    def totalNQueens(self, n: int) -> int:
        self.n = n        
        return self.backtrack(0, set(), set(), set())