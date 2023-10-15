class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        mod, arrLen = 1_000_000_007, min(arrLen, steps)
        dp, prev_dp = [0] * arrLen, [0] * arrLen
        prev_dp[0] = 1
        
        for remain in range(1, steps + 1):
            dp = [0] * (steps + 1)
            for curr in range(arrLen - 1, -1, -1):
                ans = prev_dp[curr]
                
                if curr > 0:
                    ans = (ans + prev_dp[curr - 1]) % mod
                
                if curr < arrLen - 1:
                    ans = (ans + prev_dp[curr + 1]) % mod
                dp[curr] = ans
            prev_dp = dp
        
        return dp[0]