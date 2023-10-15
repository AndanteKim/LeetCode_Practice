class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        mod = 10 ** 9 + 7
        arrLen = min(arrLen, steps)
        dp = [[0] * (steps + 1) for _ in range(arrLen)]
        dp[0][0] = 1
        
        for remain in range(1, steps + 1):
            for curr in range(arrLen - 1, -1, -1):
                ans = dp[curr][remain - 1]
                
                if curr > 0:
                    ans = (ans + dp[curr - 1][remain - 1]) % mod
                if curr < arrLen - 1:
                    ans = (ans + dp[curr + 1][remain - 1]) % mod
                
                dp[curr][remain] = ans
        
        return dp[0][steps]