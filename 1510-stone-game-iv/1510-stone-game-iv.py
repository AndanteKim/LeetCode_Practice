class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        def dp(remain: int) -> int:
            if remain in memo:
                return memo[remain]

            for i in range(1, int(remain ** 0.5) + 1):
                if not dp(remain - i * i):
                    memo[remain] = True
                    return True
            
            memo[remain] = False
            return False 
        
        memo = {0 : False}
        return dp(n)