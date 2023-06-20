class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def valid(row: int, col: int) -> bool:
            return 0 <= row < m and 0 <= col < n
        
        def backtrack(row: int, col: int, i: int, seen: Set[Tuple[int]]) -> bool:
            if i == len(word):
                return True
            
            for n_r, n_c in (row + 1, col), (row - 1, col), (row, col + 1), (row, col - 1):
                if valid(n_r, n_c) and (n_r, n_c) not in seen:
                    if board[n_r][n_c] == word[i]:
                        seen.add((n_r, n_c))
                        if backtrack(n_r, n_c, i + 1, seen):
                            return True
                        seen.remove((n_r, n_c))
            return False
        
        m, n = len(board), len(board[0])
        for row in range(m):
            for col in range(n):
                if board[row][col] == word[0] and backtrack(row, col, 1, {(row, col)}):
                    return True
        return False