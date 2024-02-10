class Solution:
    def countSubstrings(self, s: str) -> int:
        n, ans = len(s), 0
        
        if n <= 0:
            return 0
        
        dp = [[False] * n for _ in range(n)]
        
        # Base case: single letter substrings
        for i in range(n):
            dp[i][i] = True
            ans += 1
            
        # Base case: double letter substrings
        for i in range(n - 1):
            dp[i][i + 1] = (s[i] == s[i + 1])
            ans += dp[i][i + 1]
            
        # All other cases: substrings of length 3 to n
        for k in range(3, n + 1):
            i, j = 0, 0
            while j < n:
                j = i + k - 1
                dp[i][j] = dp[i + 1][j - 1] and (s[i] == s[j])
                ans += dp[i][j]
                i += 1
                j += 1
        
        return ans