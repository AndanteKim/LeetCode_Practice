class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Bottom-up space-optimized dp
        n = len(prices)
        prev_dp = [0] * 5
        
        for i in range(n - 1, -1, -1):
            dp = [0] * 5
            for left in range(0, 5):
                # Base case
                if i == n or left == 0:
                    continue
                
                # Choice 1: No transaction day
                profit1, profit2 = prev_dp[left], 0
                
                # Choice 2: Transaction day
                buy = (left % 2 == 0)
                if buy:
                    profit2 = -prices[i] + prev_dp[left - 1]
                else:
                    profit2 = prices[i] + prev_dp[left - 1]
                
                dp[left] = max(profit1, profit2)
            prev_dp = dp
        return prev_dp[4]