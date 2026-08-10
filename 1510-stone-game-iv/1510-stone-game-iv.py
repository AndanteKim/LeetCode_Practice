class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        @lru_cache(maxsize = None)
        def dp(remain: int) -> int:
            if remain == 0:
                return False

            for i in range(1, int(remain ** 0.5) + 1):
                if not dp(remain - i * i):
                    return True


            return False
        
        return dp(n)