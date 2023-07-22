class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        moves = [(2, 1), (1, 2), (-2, 1), (-1, 2), (2, -1), (1, -2), (-2, -1), (-1, -2)]
        
        @lru_cache(maxsize = None)
        def dp(r: int, c: int, k: int) -> int:
            if r < 0 or r >= n or c < 0 or c >= n:
                return 0
            if k == 0:
                return 1
            
            return sum(dp(r + dr, c + dc, k - 1) for dr, dc in moves) / 8
            
        return dp(row, column, k)