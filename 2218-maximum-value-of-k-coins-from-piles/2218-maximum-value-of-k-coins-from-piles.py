class Solution:
    def f(self, i: int, coins: int, dp: List[List[int]], piles) -> int:
        if i == 0:
            return 0
        if dp[i][coins] != -1:
            return dp[i][coins]
        current_sum = 0
        for current_coins in range(0, min(len(piles[i - 1]), coins) + 1):
            if current_coins > 0:
                current_sum += piles[i - 1][current_coins - 1]
            dp[i][coins] = max(dp[i][coins], self.f(i - 1, coins - current_coins, dp, piles) + current_sum)
        return dp[i][coins]
    
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        dp = [[-1] * (k + 1) for i in range(n + 1)]
        
        return self.f(n, k, dp, piles)