class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        dp = [0] * n
        # To store the previous required values from dp
        temp, prev = 0, 0
        
        # Generate all combinations of 'i' and 'j' in the correct order
        for i in range(n - 2, -1, -1):
            # 'prev' stores the value at dp[i + 1][j - 1];
            prev = 0
            for j in range(i + 1, n):
                # Store the value of dp[i + 1][j] temporarily
                temp = dp[j]
                
                # Case 1: Character at 'i' == character at 'j'
                if s[i] == s[j]:
                    dp[j] = prev
                    
                # Case 2: Character at 'i' doesn't equal character at 'j'.
                # Either delete character at 'i' or delete character at 'j'
                # and try to maatch the two pointers using recursion.
                # We need to take the minimum of the two results and add 1
                # representing the cost of deletion
                else:
                    # dp[j] := contain the value for dp[i + 1][j]
                    # dp[j - 1] := contain the value for dp[i][j - 1]
                    dp[j] = 1 + min(dp[j], dp[j - 1])
                
                # Copy the value of dp[i + 1][j] to 'prev'
                # For the next iteration when j = j + 1
                # 'prev' will hold the value memo[i + 1][j - 1]
                prev = temp
               
        # Return true if the minimum cost to create a palindrome by only deleting the letters
        # is less than or equal to 'k'
        return dp[n - 1] <= k