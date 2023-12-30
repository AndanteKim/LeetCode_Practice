class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        def dp(i: int, j: int) -> int:
            
            # Base case, only 1 letter remaining
            if i == j:
                return 0
            
            # Base case 2, only 2 letters remaining
            if i == j - 1:
                return s[i] != s[j]
            
            if memo[i][j] != -1:
                return memo[i][j]
        
            # Case 1: Character at 'i' equals character at 'j'
            if s[i] == s[j]:
                memo[i][j] = dp(i + 1, j - 1)
                return memo[i][j]
            
            # Case 2: Character at 'i' does not equal character at 'j'.
            # Either delete character at 'i' or delete character at 'j'
            # and try to match the two poijnters using recursion
            # We need to take the minimum of two results and add 1
            # representing the cost of deletion
            memo[i][j] = 1 + min(dp(i + 1, j), dp(i, j - 1))
            return memo[i][j]
        
        
        n = len(s)
        memo = [[-1] * n for _ in range(n)]
        
        # Return true if the minimum cost to create a palindrome by only deleting the letters
        # is less than or equal to 'k'
        
        return dp(0, n - 1) <= k