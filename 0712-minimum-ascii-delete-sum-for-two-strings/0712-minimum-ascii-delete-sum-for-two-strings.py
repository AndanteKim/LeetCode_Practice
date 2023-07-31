class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        def compute_cost(i: int, j: int) -> int:
            if i < 0 and j < 0:
                return 0
            
            if dp[i][j] != -1:
                return dp[i][j]
            
            if i < 0:
                dp[i][j] = ord(s2[j]) + compute_cost(i, j - 1)
                return dp[i][j]
            if j < 0:
                dp[i][j] = ord(s1[i]) + compute_cost(i - 1, j)
                return dp[i][j]
            if s1[i] == s2[j]:
                dp[i][j] = compute_cost(i - 1, j - 1)
            else:
                dp[i][j] = min(ord(s1[i]) + compute_cost(i - 1, j),\
                               ord(s2[j]) + compute_cost(i, j - 1))
            return dp[i][j]
            
        n1, n2 = len(s1), len(s2)
        dp = [[-1] * (n2 + 1) for _ in range(n1 + 1)]
        return compute_cost(n1 - 1, n2 - 1)