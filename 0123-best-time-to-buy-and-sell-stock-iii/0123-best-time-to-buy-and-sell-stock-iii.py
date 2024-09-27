class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Bottom-up dynamic programming
        n = len(prices)
        dp = [[0] * 5 for _ in range(n + 1)]
        
        for i in range(n, -1, -1):
            for left in range(0, 5):
                if i == n or left == 0:
                    dp[i][left] = 0
                else:
                    # Choice 1: No transaction day
                    profit1 = dp[i + 1][left]
                    
                    # Choice 2: Transaction day
                    profit2 = 0
                    buy = left % 2 == 0
                    
                    if buy:
                        profit2 = -prices[i] + dp[i + 1][left - 1]
                    else:
                        profit2 = prices[i] + dp[i + 1][left - 1]
                    
                    dp[i][left] = max(profit1, profit2)
                    
        return dp[0][4]
        