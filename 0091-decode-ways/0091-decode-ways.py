class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        
        # Ways to decode a string of size 1 is 1. Unless the string is '0'.
        # '0' doesn't have a single digit decode
        dp[1] = 0 if s[0] == '0' else 1
        
        for i in range(2, n + 1):
            
            # Check if successful single digit decode is possible
            if s[i - 1] != '0':
                dp[i] = dp[i - 1]
            
            # Check if successful two digit decode is possible
            two_digit = int(s[i - 2 : i])
            if 10 <= two_digit <= 26:
                dp[i] += dp[i - 2]
        
        return dp[n]