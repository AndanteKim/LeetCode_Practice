class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        dp = [[[0] * (k + 1) for _ in range(m + 1)] for __ in range(n + 1)]
        prefix = [[[0] * (k + 1) for _ in range(m + 1)] for __ in range(n + 1)]
        MOD = 10 ** 9 + 7
        
        for num in range(1, m + 1):
            dp[1][num][1] = 1
            prefix[1][num][1] = prefix[1][num - 1][1] + 1
        
        for i in range(1, n + 1):
            for max_num in range(1, m + 1):
                for cost in range(1, k + 1):
                    ans = (max_num * dp[i - 1][max_num][cost]) % MOD
                    ans = (ans + prefix[i - 1][max_num - 1][cost - 1]) % MOD
                    
                    dp[i][max_num][cost] += ans
                    dp[i][max_num][cost] %= MOD
                    
                    prefix[i][max_num][cost] = (prefix[i][max_num - 1][cost] + dp[i][max_num][cost]) % MOD
        
        return prefix[n][m][k]