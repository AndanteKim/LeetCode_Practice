class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [0] * n
        
        for i in range(1, n):
            dp[i] = dp[i - 1] + max(0, prices[i] - prices[i - 1])
            
        return dp[-1]
        