class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        MOD, prefix = 10 ** 9 + 7, [0] * (n + 1)
        dp = [1] * n

        for j in range(n):
            prefix[j + 1] = (prefix[j] + dp[j]) % MOD

        for _ in range(k):
            dp[0] = 0
            for j in range(1, n):
                dp[j] = (dp[j - 1] + prefix[j]) % MOD
            
            for j in range(n):
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD

        return dp[n - 1]