class Solution:
    def dp(self, i: int, holding: bool, remain: int, prices: List[List[int]], memo: List[List[List[int]]]) -> int:
        if i == self.n or remain == 0:
            return 0
        
        if memo[i][holding][remain] != -1:
            return memo[i][holding][remain]
        
        ans = self.dp(i + 1, holding, remain, prices, memo)
        
        if holding:
            ans = max(ans, prices[i] + self.dp(i + 1, 0, remain - 1, prices, memo))
        else:
            ans = max(ans, -prices[i] + self.dp(i + 1, 1, remain, prices, memo))
        
        memo[i][holding][remain] = ans
        return ans
    
    def maxProfit(self, k: int, prices: List[int]) -> int:
        self.n = len(prices)
        memo = [[[-1] * (k + 1) for _ in range(2)] for __ in range(self.n)]
        return self.dp(0, False, k, prices, memo)