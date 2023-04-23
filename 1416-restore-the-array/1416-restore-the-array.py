class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        m, n = len(s), len(str(k))
        mod = 10 ** 9 + 7
        dp = [1] + [0] * m
        
        for start in range(m):
            if s[start] == '0':
                continue
            count = 0
            
            for end in range(start, m):
                curr_number = s[start: end + 1]
                if int(curr_number) > k:
                    break
                dp[end + 1] += dp[start]
                dp[end + 1] %= mod
        return dp[-1]