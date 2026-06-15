class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        m = 1_000_000_007
        dp = [0] * ((numPeople >> 1) + 1)
        dp[0] = 1
        
        for i in range(1, (numPeople >> 1) + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - j - 1]
                dp[i] %= m

        return dp[numPeople >> 1]