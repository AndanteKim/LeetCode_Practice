class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        # readable space optimized dynamic programming
        
        n = len(prices)
        # max_profit if I
        had_stock_yesterday = -prices[0]
        # max_profit if I
        didnt_have_stock_yesterday = 0
        
        for price in prices:
            have_stock_today = max(had_stock_yesterday, didnt_have_stock_yesterday - price)
            dont_have_stock_today = max(didnt_have_stock_yesterday, had_stock_yesterday + price - fee)
            had_stock_yesterday = have_stock_today
            didnt_have_stock_yesterday = dont_have_stock_today
        
        return dont_have_stock_today