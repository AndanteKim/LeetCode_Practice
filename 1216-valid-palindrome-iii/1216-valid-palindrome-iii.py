class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        prev_dp = [0] * n
        
        # Generate all combination of the correct order
        for i in range(n - 2, -1, -1):
            dp = [0] * n
            for j in range(i + 1, n):
                # Case 1: character at 'i' equals character at 'j'
                if s[i] == s[j]:
                    dp[j] = prev_dp[j - 1]
                
                # Case 2: character at 'i' doesn't equal character at 'j'
                # Either delete character at 'i' or 'j' and try to match two pointers.
                # Then, we take two minimum of results and add 1 representing the cost of deletion.
                else:
                    dp[j] = 1 + min(prev_dp[j], dp[j - 1])
            prev_dp = dp
                    
        return prev_dp[n - 1] <= k