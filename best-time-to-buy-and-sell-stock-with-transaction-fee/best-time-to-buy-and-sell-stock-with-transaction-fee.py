class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n, hold, free = len(prices), -prices[0], 0 
        
        for i in range(1, n):
            temp = hold
            hold = max(hold, free - prices[i])
            free = max(free, hold + prices[i] - fee)
        return free
        