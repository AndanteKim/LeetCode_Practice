class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i, valley, peak = 0, prices[0], prices[0]
        ans, n = 0, len(prices)
        
        while i < n - 1:
            while i < n - 1 and prices[i] >= prices[i + 1]:
                i += 1
            valley = prices[i]
            while i < n - 1 and prices[i] <= prices[i + 1]:
                i += 1
            peak = prices[i]
            ans += peak - valley
        
        return ans
        
        