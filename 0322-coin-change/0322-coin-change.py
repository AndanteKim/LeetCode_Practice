class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        @lru_cache(maxsize = None)
        def dp(remain: int) -> None:
            if remain < 0:
                return -1
            
            if remain == 0:
                return 0
            
            min_coins = float('inf')
            for coin in coins:
                res = dp(remain - coin)
                if res != -1:
                    min_coins = min(min_coins, res + 1)
                    
            return min_coins if min_coins != float('inf') else -1
        
        return dp(amount)
        