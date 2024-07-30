class Solution:
    def minimumDeletions(self, s: str) -> int:
        n, b_cnt = len(s), 0
        dp = [0] * (n + 1)
        
        # dp[i]: The number of deletions required to
        # balance the substring s[0, i)
        for i in range(n):
            if s[i] == 'b':
                dp[i + 1] = dp[i]
                b_cnt += 1
            else:    
                # Two cases: remove 'a' or keep 'a'
                dp[i + 1] = min(dp[i] + 1, b_cnt)
                
        return dp[n]