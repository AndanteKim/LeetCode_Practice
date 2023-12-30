class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        
        # Generate all combinations of 'i' and 'j' in the correct order
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                
                # Case 1: Character at 'i' equals character at 'j'
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1]
                    
                # Case 2: Character at 'i' doesn't equal character at 'j'.
                # Either delete character at 'i' or delete character at 'j'
                # and try to match the two pointers using recursion.
                # We need to take the minimum of the two results and add 1
                # representing the cost of deletion.
                else:
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1])
                
        return dp[0][n - 1] <= k