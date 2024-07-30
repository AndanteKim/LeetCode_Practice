class Solution:
    def minimumDeletions(self, s: str) -> int:
        def dp(i: int, prev: int, length: int, memo: List[List[int]]) -> int:
            if i == n:
                return 0
            
            if memo[i][ord(s[prev]) - 97] != -1:
                return memo[i][ord(s[prev]) - 97]
            
            min_delete = float('inf')
            
            if s[prev] > s[i]:
                min_delete = min(1 + dp(i + 1, prev, length, memo), length + dp(i + 1, i, 0, memo))
            else:
                min_delete = min(dp(i + 1, i, length + 1, memo), 1 + dp(i + 1, prev, length, memo))
            
            memo[i][ord(s[prev]) - 97] = min_delete
            return min_delete
        
        n = len(s)
        memo = [[-1] * 2 for _ in range(n + 1)]
        
        return dp(0, 0, 0, memo)