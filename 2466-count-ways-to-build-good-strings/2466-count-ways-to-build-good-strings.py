class Solution:
    def dfs(self, end: int, dp: List[int], zero: int, one: int) -> int:
        if dp[end] != -1:
            return dp[end]
        count = 0
        if end >= zero:
            count += self.dfs(end - zero, dp, zero, one)
        if end >= one:
            count += self.dfs(end - one, dp, zero, one)
        
        dp[end] = count % self.mod
        return dp[end]
        
    
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        dp = [1] + [-1] * high
        self.mod = 10 ** 9 + 7
        
        return sum(self.dfs(end, dp, zero, one) for end in range(low, high + 1)) % self.mod