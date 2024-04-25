class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n, dp = len(s), [0] * 26
        ans = 0
        
        # Updating dp with the i-th character
        for i in range(n):
            curr = ord(s[i]) - ord('a')
            best = 0
            for prev in range(26):
                if abs(prev - curr) <= k:
                    best = max(best, dp[prev])
            
            # Append s[i] to the previous longest ideal subsequence
            dp[curr] = max(dp[curr], best + 1)
            ans = max(ans, dp[curr])
        return ans
        
        