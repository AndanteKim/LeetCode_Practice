class Solution:
    def knightDialer(self, n: int) -> int:
        jumps = ((4,6), (6,8), (7,9), (4,8), (0,3,9), (),\
                (0,1,7), (2,6), (1,3), (2,4))
        
        prev_dp, dp, MOD = [1] * 10, [0] * 10, 1_000_000_007
        
        for remain in range(1, n):
            dp = [0] * 10
            for square in range(10):
                curr = 0
                for next_square in jumps[square]:
                    curr = (curr + prev_dp[next_square]) % MOD
                dp[square] = curr
            prev_dp = dp
        
        ans = 0
        for square in range(10):
            ans = (ans + prev_dp[square]) % MOD
        return ans