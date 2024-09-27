class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0
        
        left_min, right_max = prices[0], prices[-1]
        n = len(prices)
        
        # Pad the right DP array with an additional zero for convenience
        left_profits, right_profits = [0] * n, [0] * (n + 1)
        
        # Construct the bidirectional DP array
        for left in range(1, n):
            left_profits[left] = max(left_profits[left - 1], prices[left] - left_min)
            left_min = min(left_min, prices[left])
            
            right = n - 1 - left
            right_profits[right] = max(right_profits[right + 1], right_max - prices[right])
            right_max = max(right_max, prices[right])
            
        max_profit = 0
        for i in range(0, n):
            max_profit = max(max_profit, left_profits[i] + right_profits[i + 1])
            
        return max_profit