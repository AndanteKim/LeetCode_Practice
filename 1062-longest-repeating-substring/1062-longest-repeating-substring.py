class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n, max_len = len(s), 0
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        # Populate the DP array
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                # Check if the characters match and
                # update the DP value
                if s[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    
                    # Update max_len
                    max_len = max(max_len, dp[i][j])
                    
        return max_len