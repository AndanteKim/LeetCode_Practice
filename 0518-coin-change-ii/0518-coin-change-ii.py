class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        @lru_cache(maxsize = None)
        def dp(remain: int, i: int, n: int) -> int:
            if remain < 0 or i >= n:
                return 0
            if remain == 0:
                return 1
            
            ways = 0
            if coins[i] <= amount:
                ways = dp(remain - coins[i], i, n) + dp(remain, i + 1, n)
            else:
                ways = dp(remain, i + 1, n)
            return ways
                    
        n = len(coins)
        return dp(amount, 0, n)