class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        dp = [[0] * (k + 1) for _ in range(m + 1)]
        prev_dp = [[0] * (k + 1) for _ in range(m + 1)]
        MOD = 10 ** 9 + 7
        
        for num in range(len(prev_dp)):
            prev_dp[num][0] = 1
            
        for i in range(n - 1, -1, -1):
            dp = [[0] * (k + 1) for _ in range(m + 1)]
            for max_so_far in range(m, -1, -1):
                for remain in range(k + 1):
                    ans = (max_so_far * prev_dp[max_so_far][remain]) % MOD
                    if remain > 0:
                        for num in range(max_so_far + 1, m + 1):
                            ans = (ans + prev_dp[num][remain - 1]) % MOD
                    dp[max_so_far][remain] = ans
            prev_dp = dp
        
        return dp[0][k]