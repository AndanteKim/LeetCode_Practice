class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, bought: bool) -> int:
            if i >= n:
                return 0
            
            profits = 0
            if bought:
                profits += max(dp(i + 1, True), prices[i] + dp(i + 1, False))
            else:
                profits += max(-prices[i] + dp(i + 1, True), dp(i + 1, False))
                
            return profits
        
        n = len(prices)
        return dp(0, False)