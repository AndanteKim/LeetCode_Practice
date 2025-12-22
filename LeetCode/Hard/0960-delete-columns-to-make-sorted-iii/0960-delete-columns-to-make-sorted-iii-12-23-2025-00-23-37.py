class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, k = len(strs), len(strs[0])
        ans, dp = 0, [1] * k

        for i in range(k - 2, -1, -1):
            for j in range(i + 1, k):
                if all(row[i] <= row[j] for row in strs):
                    dp[i] = max(dp[i], 1 + dp[j])
        
        return k - max(dp)