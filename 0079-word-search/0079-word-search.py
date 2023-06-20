class Solution:
    def valid(self, r: int, c: int) -> bool:
        return 0 <= r < self.m and 0 <= c < self.n
    
    def backtrack(self, row: int, col: int, start: int, seen: Set[Tuple[int, int]], word: str, board: List[List[str]]) -> bool:
        if start == len(word):
            return True
        
        for n_r, n_c in (row + 1, col), (row - 1, col), (row, col + 1), (row, col - 1):
            if self.valid(n_r, n_c) and (n_r, n_c) not in seen:
                if board[n_r][n_c] == word[start]:
                    seen.add((n_r, n_c))
                    if self.backtrack(n_r, n_c, start + 1, seen, word, board):
                        return True
                    seen.remove((n_r, n_c))
        
        return False
    
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.m, self.n = len(board), len(board[0])
        
        for row in range(self.m):
            for col in range(self.n):
                if board[row][col] == word[0] and self.backtrack(row, col, 1, {(row, col)}, word, board):
                    return True
        return False