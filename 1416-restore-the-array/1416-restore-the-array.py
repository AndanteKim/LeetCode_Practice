class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        m, n = len(s), len(str(k))
        mod = 10 ** 9 + 7
        dp = [1] + [0] * n
        
        for start in range(m):
            if s[start] == '0':
                dp[start % (n + 1)] = 0
                continue
            
            for end in range(start, m):
                curr_number = s[start: end + 1]
                if int(curr_number) > k:
                    break
                dp[(end + 1) % (n + 1)] += dp[start % (n + 1)]
                dp[(end + 1) % (n + 1)] %= mod
            dp[start % (n + 1)] = 0
        return dp[m % (n + 1)]