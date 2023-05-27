class Solution:
    
    def f(self, i: int, dp: List[int], stoneValue: List[int]) -> int:
        if i == self.n:
            return 0
        if dp[i] != self.not_computed:
            return dp[i]
        dp[i] = stoneValue[i] - self.f(i + 1, dp, stoneValue)
        if i + 2 <= self.n:
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - self.f(i + 2, dp, stoneValue))
        
        if i + 3 <= self.n:
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - self.f(i + 3, dp, stoneValue))
        
        return dp[i]
    
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        self.n, self.not_computed = len(stoneValue), 10 ** 9
        dp = [self.not_computed] * (self.n + 1)
        
        dif = self.f(0, dp, stoneValue)
        
        if dif > 0:
            return "Alice"
        if dif < 0:
            return "Bob"
        
        return "Tie"
        