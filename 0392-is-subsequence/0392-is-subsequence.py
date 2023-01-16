class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        source_len, target_len = len(s), len(t)
        
        if source_len == 0:
            return True
        
        dp = [ [0] * (target_len + 1) for _ in range(source_len + 1)]
        
        for col in range(1, target_len + 1):
            for row in range(1, source_len + 1):
                if s[row - 1] == t[col - 1]:
                    dp[row][col] = dp[row-1][col-1] + 1
                else:
                    dp[row][col] = max(dp[row][col - 1], dp[row - 1][col])
            
            if dp[source_len][col] == source_len:
                return True
        
        return False