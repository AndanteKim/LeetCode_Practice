class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        m = 1_000_000_007
        dp = [-1] * ((numPeople >> 1) + 1)
        dp[0] = 1

        def cal_dp(i: int) -> int:
            if dp[i] != -1:
                return dp[i]
            dp[i] = 0
            for j in range(i):
                dp[i] += cal_dp(j) * cal_dp(i - j - 1)
            dp[i] %= m
            return dp[i]
        
        return cal_dp(numPeople >> 1)