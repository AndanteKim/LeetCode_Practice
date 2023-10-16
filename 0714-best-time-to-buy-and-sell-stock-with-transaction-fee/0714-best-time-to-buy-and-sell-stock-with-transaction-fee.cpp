class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, hold: int) -> int:
            if i >= n:
                return 0
            
            profit = 0
            if not hold:
                profit = max(-prices[i] + dp(i + 1, True), dp(i + 1, hold))
            else:
                profit = max(prices[i] - fee + dp(i + 1, False), dp(i + 1, hold))
                
            return profit
        
        n = len(prices)
        # -1 := stands for no buying
        return dp(0, False)