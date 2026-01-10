class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        # Return the minimum cost to make s1[0...i] and s2[0...j] equal
        def dp(i: int, j: int) -> int:
            # Base case
            if i < 0 and j < 0:
                return 0

            if i < 0:
                return ord(s2[j]) + dp(i, j - 1)
            
            if j < 0:
                return ord(s1[i]) + dp(i - 1, j)
            
            if memo[i][j] != -1:
                return memo[i][j]

            # Call the sub-problem depending on s1[i] and s2[j]
            # Save the computed result
            if s1[i] == s2[j]:
                memo[i][j] = dp(i - 1, j - 1)
            else:
                memo[i][j] = min(
                    ord(s1[i]) + dp(i - 1, j),
                    ord(s2[j]) + dp(i, j - 1)
                )

            return memo[i][j]

        m, n = len(s1), len(s2)
        memo = [[-1] * n for _ in range(m)]
        return dp(m - 1, n - 1)