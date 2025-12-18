class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        profit_sum, price_sum = [0] * (n + 1), [0] * (n + 1)

        for i in range(n):
            profit_sum[i + 1] = profit_sum[i] + prices[i] * strategy[i]
            price_sum[i + 1] = price_sum[i] + prices[i]
        
        ans = profit_sum[n]

        for i in range(k - 1, n):
            left_profit = profit_sum[i - k + 1]
            right_profit = profit_sum[n] - profit_sum[i + 1]
            change_profit = price_sum[i + 1] - price_sum[i - (k >> 1) + 1]
            ans = max(ans, left_profit + change_profit + right_profit)

        return ans