class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for coin in coins:
            for curr in range(coin, amount + 1):
                dp[curr] = min(dp[curr], dp[curr - coin] + 1)
                
        return -1 if dp[amount] == float('inf') else dp[amount]