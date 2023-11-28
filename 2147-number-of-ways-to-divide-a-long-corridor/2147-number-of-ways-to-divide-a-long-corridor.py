class Solution:
    def numberOfWays(self, corridor: str) -> int:
        n, prev_dp, MOD = len(corridor), [0, 0, 1], 1_000_000_007
        
        for i in range(n - 1, -1, -1):
            dp = [0, 0, 0]
            if corridor[i] == 'S':
                dp[0] = prev_dp[1]
                dp[1] = prev_dp[2]
                dp[2] = prev_dp[1]
            else:
                dp[0] = prev_dp[0]
                dp[1] = prev_dp[1]
                dp[2] = (prev_dp[0] + prev_dp[2]) % MOD
            
            prev_dp = dp
        
        return prev_dp[0]